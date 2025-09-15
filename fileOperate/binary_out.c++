#include <fstream>
#include <cstring>
#include <iostream>
using namespace std;
class Person{
public:
    Person(const char str[64],int num){
        this->m_Age = num;
        strcpy(m_Name,str);
    }
    char m_Name[64];
    int m_Age;
};


int main(void)
{
    ofstream ofs;
    ofs.open("person.txt",ios::out | ios::binary); 
    if(!ofs.is_open()) {cout << "FILE OPEN FAILED!" << endl; return -1;}
    Person p = {"张三",18};
    ofs.write((const char*)&p,sizeof(Person));
    ofs.close();
    return 0;
}