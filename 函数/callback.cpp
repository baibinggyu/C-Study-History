#include <iostream>
void Print(){
    std::cout << "Hello World!" << std::endl;
}
void func(void (*p)(void)){
    p();
}
int main(void)
{   
    func(Print);
    return 0;
}