//写文件
#include <fstream>
#include <iostream>
using namespace std;
int main(void)
{
    ofstream osf;
    osf.open("testWrite.txt",ios::out | ios::app);
    string name,sex;
    int age;
    cout << "请输入姓名、年龄和性别" << endl;
    cin >> name >> age >> sex;
    osf << "姓名:" << name << ' ';
    osf << "年龄:" << age << ' ';
    osf << "性别:" << sex << endl;  

    osf.close();
    return 0;
}