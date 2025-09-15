#include <iostream>
#include <string>
class MyPrint{
    public:
        MyPrint(){
            this->cnt = 0;
        }
        void operator()(std::string test){
            std::cout << test << std::endl;
            this->cnt++;
        }
        int count(void){return this->cnt;}
    private:
        int cnt;
};

//函数对象超出普通函数概念，函数对象可以有自己的状态
void test(){
    MyPrint myprin;
    myprin("Hello World!");
    myprin("Hello World!");
    myprin("Hello World!");
    myprin("Hello World!");
    std::cout << "myprint_count : "<< myprin.count() << std::endl; //记录内部的状态
}
void doPrint(MyPrint& mp,std::string test){
    mp(test);
}
//函数对象可以作为参数传递
void test02(){
    MyPrint myprint;
    doPrint(myprint,"Hello cpp");
}
int main(void)
{
    // test();
    test02();
    return 0;
}