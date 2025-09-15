#include <iostream>
#include <mutex>
#include <thread>

int shared_data = 0;
std::timed_mutex mtx;
void func(void){
    for(int i = 0;i < 2;++i)
    {
        // std::lock_guard<std::timed_mutex> lg(mtx); //自动进行枷锁
        std::unique_lock<std::timed_mutex> lg(mtx,std::defer_lock);
        // lg.lock();
        if (lg.try_lock_for(std::chrono::seconds(2)))
        {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            // mtx.lock() //不需要了
            shared_data++;
            // mtx.unlock(); // 不需要了
        }
       
    }
}

int main(void){

    // std::mutex mt;
    // mt.lock();  //第一次只是锁上了
    // std::cout << "Hello World!" << std::endl;
    // mt.lock(); // 第二次发生阻塞
    // std::cout << "OVER!" << std::endl;

    std::thread t01(func);
    std::thread t02(func);
    t01.join();
    t02.join();
    std::cout << shared_data << std::endl;


    
    return 0;
}