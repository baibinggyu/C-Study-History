#include <iostream>
using namespace std;
int main(void)
{
    // 一定要写 {}
    try {throw out_of_range("越界异常");}
    catch(exception &e) {cout << e.what() << endl;}
    

    return 0;
}