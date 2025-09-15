#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
class Person{
    public:
        Person(){}
        Person(const char str[64],int num){
            this->m_Age = num;
            strcpy(m_Name,str);
        }
        char m_Name[64];
        int m_Age;
    };    
int main(void)
{
    ifstream ifs;
    ifs.open("person.txt",ios::binary | ios::in);
    if(!ifs.is_open()){
        cout << "FILE FAILED OPEN!" << endl;
        return -1;
    }
    Person p;
    ifs.read((char*)&p,sizeof(Person));
    cout << p.m_Age << ' ' << p.m_Name << endl;



    return 0;
}