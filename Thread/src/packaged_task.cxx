#include <iostream>
#include <future>
int func(void){
    int i ;
    for(i = 0;i < 1000;++i){
        i++;
    }
    return i;
}
int main(int argc,char* argv[]){
    std::packaged_task<int(void)> task(func);  // 没有自动开始线程

    auto future_result = task.get_future();

    std::thread t1(std::move(task)); // 开始运行
    std::cout << func() << std::endl;

    t1.join();
    std::cout << future_result.get() << std::endl;



    return 0;
}