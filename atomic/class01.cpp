#include <thread>
#include <atomic>
#include <mutex>
#include <iostream>
#include <vector>
#include <algorithm>
std::atomic<int> count(0);
constexpr int SIZE = 1e5;
void atomicAdd(){
    for(int i = 0; i < SIZE;i++) count++;
}

int main(void){
    std::vector<std::thread> t;
    t.push_back(std::thread(atomicAdd));
    t.push_back(std::thread(atomicAdd));
    std::for_each(t.begin(),t.end(),[](std::thread& t){t.join();});
    std::cout << count << std::endl;
    return 0;
}