#include <iostream>
#include <string>
template<class T1,class T2>
class Person{
    public:
        Person(T1 name,T2 age):m_Name(name),m_Age(age){}
        void showPerson(void)
            {
                std::cout << "姓名:" << this->m_Name << ' ' << "年龄:" << this->m_Age << std::endl;
            }
    private:
        T1 m_Name;
        T2 m_Age;
};

void test01()
{
    Person<std::string,int> p("孙悟空",100);
    p.showPerson();
}
template<typename T>
void printClass(T& p){
    p.showPerson();
    std::cout << "T:" << typeid(T).name() << std::endl;
}
template<typename T1,typename T2>
void printPerson(Person<T1,T2>& p)
{
    p.showPerson();
    std::cout << "T1:" << typeid(T1).name() << std::endl<< "T2:" << typeid(T2).name() << std::endl;
}
void test02(void){
    Person<std::string,int> p("猪八戒",90);
    // printPerson(p);
    printClass(p);
}
int main(void)
{
    // test01();
    test02();
    return 0;
}