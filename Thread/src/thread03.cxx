#include <iostream>
#include <memory>
#include <thread>

class A{
public: 
    void foo(){std::cout  << "Hello World!" << std::endl;}
};
 

void test(void){
    std::shared_ptr<A> a = std::make_shared<A>(); 
    // 成员函数指针，&a 相当this指针
    std::thread t(&A::foo,a);

    t.join();
}
int main(void)
{
    
    test();
    return 0;
}