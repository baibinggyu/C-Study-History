#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>
std::atomic<int> shared_data; // 性能会有所提升
void func(void){
    for(int i = 0;i < 100000;i++){
        shared_data++;  // 不需要手动锁 解锁
    }
}

int main(int argc,char* argv[]){
    std::thread t1(func);
    std::thread t2(func);
    t1.join();
    t2.join();
    std::cout << "shared_data : " << shared_data.load() << std::endl;
    shared_data.store(1); // 保证是原子性的
    std::cout << "shared_data : " << shared_data.load() << std::endl;


    return 0;
}