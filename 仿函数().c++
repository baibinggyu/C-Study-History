#include <iostream>
#include <string>
class MyPrinter{
public:
    void operator()(std::string str) const{
        std::cout << str << std::endl;
    }
};
int main(void){
    MyPrinter pt;
    pt("Hello World!");
    //匿名函数对象
    MyPrinter()("你好!");//当前行执行完成立刻被释放
    return 0;
}