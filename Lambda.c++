#include <iostream>
using namespace std;
int main(void)
{
    int num = 100;
    auto foo = [num](void)->int{return num;};
    int ret = foo();
    cout << ret << endl;
    return 0;
}