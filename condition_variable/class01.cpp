#include <condition_variable>
#include <thread>
#include <atomic>
#include <mutex>
#include <iostream>
#include <chrono>
#include <queue>
#include <algorithm>
std::queue<int> q;
std::mutex mtx;
std::condition_variable cv;
int done = 0;
constexpr int CNT = 1e4;
int count = 0;
void producer(){
    for(int i = 0;i < CNT;i++){
        {
            std::unique_lock<std::mutex> lock(mtx);
            q.push(i);
            std::cout << "Producer : " << i << std::endl;
        }
            cv.notify_all();
    }
    {
        std::unique_lock<std::mutex> lock(mtx);
        done ++;
    }
    cv.notify_all();
} 

void consumer(){
    while(true){
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock,[]()->bool{return !q.empty() || done;});
        if(!q.empty()){
            std::cout << "Comsumer : " << q.front() << std::endl;
            q.pop();
            count ++;
        }else if (done == 2){
            break;
        }
    }
}
#define SIZE 10
int main(void){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::thread t01(producer),t02(producer);
    std::vector<std::thread> arr;
    for(int i = 0; i < SIZE;i++) arr.push_back(std::thread(consumer));
    for(int i = 0;i < SIZE;i++) arr[i].join();
    t01.join(),t02.join();
    std::cout << "count = " << count << std::endl;
    return 0;
}
