#include <iostream>
#include <string>
#include <climits>
class AbstractCalculator{
    public:
    AbstractCalculator(int num01,int num02) : num01(num01),num02(num02){}
        virtual int getResult() = 0;
        int num01,num02;
};
class AddCalculator : public AbstractCalculator
{
    public:
    AddCalculator(int num01,int num02) : AbstractCalculator(num01,num02){}
        virtual int getResult() override{
            return num01 + num02;
        }
};
void type(AbstractCalculator& add){std::cout << "我是左值!" << std::endl;(void)add;}
void type(AbstractCalculator&& add){std::cout << "我是右值!" << std::endl;(void)add;}
int main(void)
{
    // std:: cout << &AddCalculator(10,20) << std::endl; //不能取地址 右值
    /*
    AddCalculator temp(10,10);
    std::cout << &temp << std::endl; 可以取地址 左值
    */
    AbstractCalculator&& add = AddCalculator(10,20);
    std::cout << add.getResult() << std::endl;
    type(add);
    return 0;
}