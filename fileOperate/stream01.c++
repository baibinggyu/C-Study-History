#include <iostream>
#include <string>
#define INT_MIN -2100000000
using namespace std;

int main(void)
{
    char* str = nullptr;
    int num = INT_MIN;
    cin.getline(str,20);
    cin >> num;
    
    cout << "这是str:" << str << endl;
    cout << "这是num:" << num << endl;

    return 0;
}