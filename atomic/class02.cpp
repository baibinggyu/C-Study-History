#include <atomic>
#include <thread>
#include <iostream>
int main(void){
    std::atomic<int> ai(10);
    // load  是原子操作
    std::cout << "value = "<< ai.load() << std::endl;
    // 修改
    ai.store(20);
    std::cout << "new value = "<< ai.load() << std::endl;
    // ai -> int 没有函数重载，而是atomic里面有类型转换函数 
    std::cout << "current value = " << ai << std::endl;
    // 读取旧值，设置新值，返回旧值 也是原子操作,old不是原子操作
    auto old = ai.exchange(30);
    std::cout << "old value = " << old << std::endl;
    std::cout << "new value = "<<ai.load() << std::endl;
    ai += 10;
    std::cout << "after += " << ai << std::endl;

    // cas操作
    // if val == expected
    // atomic = desired return true
    // else expected = val return false
    return 0;
}