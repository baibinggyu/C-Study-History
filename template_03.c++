#include <iostream>
//类模板中成员在调用的时候才会创建

class Person1
{
    public:
        void showPerson1(void){std::cout << "Person1 show" << std::endl;}
    private:

};
class Person2
{
    public:
        void showPerson2(void){std::cout << "Person2 show" << std::endl;}
    private:

};
template <class T>
class MyClass{
    public:
        T obj;
        void func1(void){
            obj.showPerson1();
        }
        void func2(void){
            obj.showPerson2();
        }
};
void test01(void)
{
    MyClass<Person1> c;
    c.func1();
    // c.func2();
}
int main(void)
{
    test01();
    return 0;
}