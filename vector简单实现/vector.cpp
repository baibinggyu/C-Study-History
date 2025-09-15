#include "vector.hpp"
int main(void)
{
    vector<std::string> arr(10,"Hello World!");
    for(size_t i = 0;i < arr.size();i++)
        std::cout << arr[i] << ' ' << std::endl;
    arr.push_back("你好!");
    std::cout << arr[arr.size() - 1] << std::endl;
    arr.pop_back();
    for(size_t i = 0;i < arr.size();i++)
        std::cout << arr[i] << ' ' << std::endl;
    std::cout << arr.size() << std::endl;
    arr.erase("Hello World!");
    std::cout << arr.size() << std::endl;
    std::cout <<"---------------------" << std::endl;
    for(size_t i = 0;i < arr.size();i++)
        std::cout << arr[i] << ' ' << std::endl;
    return 0;
}