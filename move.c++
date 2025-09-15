#include <iostream>
#include <vector>
#include <utility>
int main(void)
{
    std::vector<int> v1 = {1,2,3};
    std::vector<int> v2 = std::move(v1); //不调用深拷贝构造
    v1.push_back(4);                                                                                
    std::vector<int>::iterator it = v1.begin();
    while(it != v1.end()) std::cout << *it++ << std::endl;
    return 0;
}