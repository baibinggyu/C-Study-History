#include <iostream>
#include <string>
template<typename T>
void swap(T& m,T& n)
{
    T temp = m;
    m = n;
    n = temp;
}
void test01(){
    std::string a = "我是a";
    std::string b = "我是b";
    swap(a,b);
    std::cout << b << std::endl << a << std::endl;
}
void test(){
    int a = 10;
    int b = 20;
    swap<int>(a,b);//显示指定数据类型
    std::cout << a << ' ' << b << std::endl;
}
int main(void)
{
    test();
    return 0;
}