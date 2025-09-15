#include <iostream>
#include <mutex>
#include <string>
#include <thread>
#include <condition_variable>
#include <queue>

std::queue<int> q_queue;
std::condition_variable q_cv;
std::mutex mtx;
void Producer(void){
    for(int i = 0;i < 10;++i){
        std::unique_lock<std::mutex> mt(mtx);
        q_queue.push(i);
        q_cv.notify_one();
        std::cout << "Producer:" << i << std::endl;
    }
    std::this_thread::sleep_for(std::chrono::microseconds(100));

}


void Consumer(void){
    while(true){
        std::unique_lock<std::mutex> mt(mtx);
        q_cv.wait(mt,[]()->bool{return !q_queue.empty();}); // 会临时释放锁 mt，并阻塞当前线程
        int value = q_queue.front();
        q_queue.pop();
        std::cout <<"Consume:" <<value << std::endl;

    }
}

int main(void){
    // 生产者与消费者模型
    std::thread t2(Consumer);
    std::thread t1(Producer);
    t1.join();
    t2.join();


    return 0;
}