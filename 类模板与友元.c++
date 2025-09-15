#include <iostream>
#include <string>
template<class T1,class t2>
class Person;
template<class T1,class T2>
void printPerson02(Person<T1,T2>& p){std::cout<<"类外实现" << ' ' << "姓名:" << p.name << ' '  << "年龄:" << p.age << std::endl;}
template<class T1,class T2>
class Person{
    //全局函数类内实现
       friend void printPerson(Person<T1,T2>& p){std::cout << "姓名:" << p.name << ' '  << "年龄:" << p.age << std::endl;}
    //全局函数类外实现
    //空模板的参数列表
    //如果全局函数是类外实现 需要让编译器提提前知道这个函数的存在
       friend void printPerson02<>(Person<T1,T2>& p);
    public:
        Person(T1 name,T2 age):name(name),age(age){}
    private:
        T1 name;
        T2 age;
};
//类外实现

void test01(){
    Person<std::string,int> p("百余",18);
    printPerson02(p);
}
int main(void){

    test01();
    return 0;
}