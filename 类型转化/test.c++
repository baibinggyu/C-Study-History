
#include <iostream>
using namespace std;
template<class T1,class T2>
class Person{
    public:
        Person(T1 name,T2 age):m_Name(name),m_Age(age){}
        void showPerson(void);
        T1 m_Name;
        T2 m_Age; 
};
template<class T1,class T2>
void Person<T1,T2>::showPerson(){
    cout << this->m_Name<< ":" << this->m_Age << endl;
}
int main(void){
    Person<char*,int> p(const_cast<char*>("abc"),18);
    p.showPerson();
   
    return 0;
}