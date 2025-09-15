#include <iostream>
#include <vector>
#include <algorithm>
class MyCompare{
public:
    bool operator()(int num,int num02){
        return num > num02;
    }
};
void test01(void)
{
    std::vector<int> arr;
    arr.push_back(10);
    arr.push_back(40);
    arr.push_back(20);
    arr.push_back(30);
    arr.push_back(50);
    std::sort(arr.begin(),arr.end(),MyCompare());
    for(int temp : arr)
        std::cout << temp << ' ' << std::endl;
}
int main(void)
{
    test01();
    return 0;
}