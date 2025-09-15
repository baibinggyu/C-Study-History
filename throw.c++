#include <iostream>
#include <stdexcept>
int main(void)
{
    int temp = 0;
    
    try{
        if(temp == 0) throw temp;
    }
    catch (int num){
        std::cout << "处理错误!" << num << std::endl;
    }
    std::cout << "结束" << std::endl;
    return 0;
}