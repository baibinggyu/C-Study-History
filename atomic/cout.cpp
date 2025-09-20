#include <iostream>
#include <atomic>
#pragma pack(push,1)
struct Demo
{
    char temp;
    int a;
};

int main(void){
    std::atomic<int> ai(10);
    if(ai.is_lock_free())std::cout << "int -> 硬件级别的原子操作!" << std::endl;
    else std::cout << "int -> 操作系统级别的原子操作!" <<std::endl;
    
    std::cout << sizeof(Demo) << std::endl;
    std::atomic<Demo> d;
    if(d.is_lock_free())std::cout << "Demo -> 硬件级别的原子操作!" << std::endl;
    else std::cout << "Demo -> 操作系统级别的原子操作!" <<std::endl;

    return 0;
}