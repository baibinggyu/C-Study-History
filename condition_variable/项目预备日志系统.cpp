#include <iostream>
#include <fstream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <string>
#include <atomic>

class Logger {
public:
    Logger(const std::string& filename)
        : done(false), logFile(filename, std::ios::out | std::ios::app) 
    {
        worker = std::thread(&Logger::process, this);
    }

    ~Logger() {
        {
            std::unique_lock<std::mutex> lock(mtx);
            done = true;
        }
        cv.notify_all();
        worker.join();
    }

    void log(const std::string& msg) {
        {
            std::unique_lock<std::mutex> lock(mtx);
            messages.push(msg);
        }
        cv.notify_one();
    }

private:
    void process() {
        std::unique_lock<std::mutex> lock(mtx);
        while (!done || !messages.empty()) {
            cv.wait(lock, [&] { return !messages.empty() || done; });
            while (!messages.empty()) {
                logFile << messages.front() << "\n";
                messages.pop();
            }
            logFile.flush();
        }
    }

    std::thread worker;
    std::mutex mtx;
    std::condition_variable cv;
    std::queue<std::string> messages;
    std::ofstream logFile;
    bool done;
};

int main() {
    Logger logger("app.log");

    std::thread t1([&] {
        for (int i = 0; i < 5; ++i)
            logger.log("Thread1: message " + std::to_string(i));
    });

    std::thread t2([&] {
        for (int i = 0; i < 5; ++i)
            logger.log("Thread2: message " + std::to_string(i));
    });

    t1.join();
    t2.join();

    logger.log("Main thread finished.");
}
