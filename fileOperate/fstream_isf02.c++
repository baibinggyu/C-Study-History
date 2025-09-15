#include <fstream>
#include <iostream>
#include <string>
using namespace std;
int main(void)
{
    // char buf[1024];
    ifstream isf;
    isf.open("cost-2025-4.csv",ios::in);
    if(!isf.is_open()){cout << "FILE OPEN ERROR！" << endl;return -1;}
    //1.
    // isf >> buf;
    // cout << buf << endl;
    //2.
    // while(isf >> buf){
    //     cout << buf << endl;
    // }
    //3.
    // while(isf.getline(buf,sizeof(buf))) cout << buf << endl;
    //4.
    string buf;
    while(getline(isf,buf)) cout << buf << endl;
    isf.close();
    return 0;
}