#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>
#include <chrono>
std::atomic<int> counter{0};
std::mutex mu;
constexpr int SIZE = 100;
void worker(){
    for(int i = 0;i < SIZE ; i++){
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        int old_value = counter.load();
        int new_value;
        do{
            new_value = (old_value == 20) ? 0 : old_value + 1;
        }while(!counter.compare_exchange_strong( old_value,new_value));
        std::lock_guard<std::mutex> lock(mu);
        std::cout << old_value << '\t' << std::this_thread::get_id() << std::endl;
    }
}

int main(void){
    std::thread t01(worker),t02(worker);
    t01.join(),t02.join();


    return 0;
}