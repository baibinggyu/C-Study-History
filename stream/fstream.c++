#include <iostream>
#include <fstream>
using namespace std;
int main(void){
    fstream fs("test.txt",std::ios::in | std::ios::out | std::ios::app);
    if(!fs.is_open()) {cerr << "FILE OPEN FAILED!"<<endl;return -1;}
    fs << "这是测试文本\n";
    // 注意fp的位置
    fs.seekg(0);
    string str;
    fs >> str;
    cout << str;
    return 0;
}