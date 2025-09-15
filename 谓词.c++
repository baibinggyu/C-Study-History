#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <utility>
#define SIZE 10
//返回bool的仿函数
//一元谓词、二元谓词指的是行参的数量
class GreaterFive
{
    public:
        bool operator()(int val){
            return val > 5;
        }
};
void test01(void)
{
    std::vector<int> arr;
    for(int i = 0;i < SIZE;++i)
        arr.push_back(i);
    std::vector<int>::iterator it = find_if(arr.begin(),arr.end(),GreaterFive());
    if(it == arr.end()) std::cout << "未找到大于5的数字" << std::endl;
    else std::cout << "找到大于5的数字" << std::endl;

}
int main(void){
    test01();
    return 0;
}