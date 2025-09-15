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

    std::future<int> future_result = std::async(std::launch::async,func);
    std::cout << func() << std::endl;


    std::cout << future_result.get() << std::endl;
    return 0;
}