#include <iostream>
#include <functional>
int main(void)
{
    std::function<void()> func = []{std::cout << "Hello World!" << std::endl;};
    func();
    return 0;
}