#include <iostream>
#include <thread>
#include <memory>
#include <mutex>

std::mutex m1,m2;
// 死锁
// void func_1(void){
//     for(int i = 0;i < 500;++i){
//         m1.lock();
//         m2.lock();
//         m1.unlock();
//         m2.unlock();
//     }
   
// }
// void func_2(void){
//     for(int i = 0;i < 500;++i){
//         m2.lock();
//         m1.lock();
//         m1.unlock();
//         m2.unlock();
//     }
    
// }

// 没问题
void func_1(void){
    for(int i = 0;i < 500;++i){
        m1.lock();
        m2.lock();
        m1.unlock();
        m2.unlock();
    }
   
}
void func_2(void){
    for(int i = 0;i < 500;++i){
        m1.lock();
        m2.lock();
        m1.unlock();
        m2.unlock();
    }
    
}
int main(void)
{
    std::thread t01(func_1);
    std::thread t02(func_2);
    t01.join();
    t02.join();

    std::cout << "over!" << std::endl;

    return 0;
}