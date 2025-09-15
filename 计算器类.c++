#include <iostream>
#include <string>
#include <climits>
class Calculator{
    public:
    Calculator(int num01,int num02) : num01(num01),num02(num02){}
    Calculator(void) : num01(0),num02(0){}
        int getResult(std::string oper)
        {
             if(oper == "+") return num01 + num02;
             else if (oper == "-") return num01 - num02;
             else if (oper == "*") return num01 * num02;
             else if (oper == "/")return num01 / num02;
             else {std::cout << "请输入合法的符号!" << std::endl;return INT_MIN;}
        }
    private:
        int num01,num02;
};
int main(void)
{
    Calculator cal(100,20);
    std::cout <<cal.getResult("/")<< std::endl;;
    return 0;
}