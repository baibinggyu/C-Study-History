#include <atomic>
#include <thread>
#include <iostream>

int main(void){
    std::atomic<int> ai(10);
    int expected = 10,desired = 20;
    ai.compare_exchange_strong(expected,desired);
    std::cout << ai.load() << std::endl;
    return 0; 
}