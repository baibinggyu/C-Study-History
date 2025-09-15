#ifndef PERSON_HPP
#define PERSON_HPP
#include <iostream>
#include <string>
template <class T1,class T2>
class Person{
    public:
        Person(T1 name,T2 age):m_Name(name),m_Age(age){}
        void showPerson(void);
        T1 m_Name;
        T2 m_Age; 
};
template <class T1,class T2>
void Person<T1,T2>::showPerson(void){std::cout << "姓名:" << this->m_Name << ' '  << "年龄:" << this->m_Age << std::endl;}
#endif