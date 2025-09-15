#include <iostream>
#include <thread>
std::thread t;
int * arr = nullptr;
void foo(int& x){x += 1;}
// 未定义行为 a 在test结束之后就会被释放，在join处阻塞，按理会运行时候出问题
void test(void){
    int a = 1;
    arr = &a;
    t = std::thread(foo,std::ref(a));
}

int main(void)
{
    test();
    t.join(); // 在这里阻塞
    std::cout << *arr << std::endl; // 输出的是随机数,因为原本的地址失效
    return 0;
}