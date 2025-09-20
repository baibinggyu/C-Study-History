#include <chrono>
#include <iostream>
int main(void){
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now().time_since_epoch()).count()<< std::endl;

    return 0;
}