#include <iostream>
#include <functional>
class MyMath{
public:
    MyMath(){std::cout << "默认构造函数!" << std::endl;}
    MyMath(const MyMath* math){std::cout << "默认拷贝构造函数!" << std::endl;}
    int add(int a,int b){return a + b;}
};
typedef int(MyMath::* FUNC)(int,int);


int main(void){

    FUNC f = &MyMath::add;
    MyMath m;
    std::cout << (m.*f)(1,2) << std::endl;
    int a = 10;
    int b = 20;
    auto p = std::bind(&MyMath::add,std::ref(m),a,b); // 获取成员函数指针
    std::cout << p() << std::endl;
    return 0;
}