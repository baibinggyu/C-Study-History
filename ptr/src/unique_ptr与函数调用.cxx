#include <iostream>
#include <memory>
#include "cat.h"
void do_with_cat_pass_value(std::unique_ptr<Cat> c){
    c->cat_info();
}
// 如果只是想修改值，建议加上cosnt关键字
void do_with_cat_pass_ref(const std::unique_ptr<Cat> &c){
    c->cat_info();
    c->set_cat_name("我是修改之后的名字!");
    // c.reset();
}
int main(void){
    //不能cpoy智能move
    std::unique_ptr<Cat> cat = std::make_unique<Cat>("咪咪");
    do_with_cat_pass_value(std::move(cat));
    //  内存问题
    // cat->cat_info()；
    

    //自动调用move 从析构函数可以看出
    do_with_cat_pass_value(std::make_unique<Cat>("大姚"));

    do_with_cat_pass_value(std::move(std::make_unique<Cat>("大姚02")));

    // no const
    std::unique_ptr<Cat> c = std::make_unique<Cat>("ff");
    do_with_cat_pass_ref(c);
    std::cout << "c address:" << c.get() << std::endl;

    return 0;
}