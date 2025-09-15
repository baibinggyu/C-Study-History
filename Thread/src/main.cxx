#include "My_Thread.h"

void Print(std::string str)
{
   for(int i = 0;i < 1000000;++i)
        std::cout << i << std::endl;
}

int main(void)
{
    std::thread thread01(Print,"Hello Thread!");
    if(thread01.joinable()) thread01.join(); // 在这里会发生阻塞
    std::cout << "程序结束!" << std::endl;

    return 0;
}