#include <iostream>
template<class T1,class T2>
class Person{
    public:
        Person(T1 name,T2 age);
        void showPerson(void);
        T1 name;
        T2 age;
};
template<class T1,class T2>
Person<T1,T2>::Person(T1 name,T2 age){
    this->name = name;
    this->age = age;
}
template<class T1,class T2>
void Person<T1,T2>::showPerson(void){
    std::cout << this->name << ' ' << this->age << std::endl;
}
int main(void)
{
    Person<std::string, int> p("Alice", 25);  // 实例化模板类
    p.showPerson();
    return 0;
}