#include <iostream>
#include <functional>
void func(int& a){
    a++;
    std::cout << a << std::endl;
    std::cout << "f adress:" << &a << std::endl;
}
int main(void){
    int a = 10;
    auto f = std::bind(func,a); 
    f(); // 结果是 11 
    std::cout << a << std::endl; // 结果是10 说明右值引用
    auto p = std::bind(func,std::ref(a)); 
    std::cout << "main adress:" << &a << std::endl;
    p();
    std::cout << a << std::endl;
    std::cout << "main adress:" << &a << std::endl;

    

    return 0;
}