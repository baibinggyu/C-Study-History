#include <iostream>
#include <memory>
#include <thread>
#include <mutex>
#include <string>
static Log * log = nullptr;
static std::once_flag once;
class Log{
public:
    Log(){}
    Log(const Log& log) = delete;
    Log &operator=(const Log& log) = delete;
    static Log& GetInstance(){
        // static Log log; // 懒汉模式
        // return log;
        //饿汉模式
        // static Log * log = nullptr;
        if(!log) log = new Log;
        std::call_once(once,init);      //   不能在main中使用,只能在多线程中使用
        return *log;
    }
    void PrintLog(std::string msq){
        std::cout << __TIME__<< ':'<< msq << std::endl;
    }

    static void init(){
        if(!log) log = new Log;
    }




};

void Print_Error(void){
    Log::GetInstance().PrintLog("Eror");

}
int main(void){
    std::thread t1(Print_Error);
    std::thread t2(Print_Error);

    // 一开始 log 都为nullptr
    // 两个if都判定log为空，同时new

    t1.join();  
    t2.join();


    return 0;
}