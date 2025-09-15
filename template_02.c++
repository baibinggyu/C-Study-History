#include <iostream>
#include <string>
template<class NameType = std::string,class AgeType = int>  
//没有自动类型推导的使用方式
//可以有默认参数
class Person{
    public:
        Person(NameType name,AgeType age):m_name(name),m_Age(age){}
        void showPerson(void){std::cout << "姓名:" << this->m_name << ' ' << "年龄:" << this->m_Age << std::endl;}
        NameType m_name;
        AgeType m_Age;
        ~Person(){
            std::cout << ' ' << this->m_name<< "析构" << std::endl;
        }
};
void test01(){
    Person<std::string,int> p("孙悟空",1000);
    p.showPerson();
}
void test02(){
    Person<std::string> p("百余",1000); 
    //有就使用，没有就默认
    p.showPerson();
}   
int main(void)
{
    test01();
    test02();
    return 0;
}