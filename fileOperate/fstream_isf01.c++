#include <fstream>
#include <iostream>
using namespace std;
int main(void)
{
    ifstream isf;
    isf.open("cost-2025-4.csv",ios::in);
    if(!isf.is_open()){cout << "ios::in Error" << endl; return -1;}
    string str;
    int count =  0;
    while(!isf.eof()){
        isf >> str;
        cout << str << endl;
        cout << "这是第" << ++count << "输出!" << endl;
    }

    isf.close();
    return 0;
}