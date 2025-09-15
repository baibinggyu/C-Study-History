#include <iostream>
#include "cat.h"
#include <memory>

std::unique_ptr<Cat> get_unique_ptr(){
    return std::make_unique<Cat>("函数中传出来的"); // 会去看是不是可以move移动返回
}

int main(void)
{
    std::unique_ptr<Cat> unique_cat = std::make_unique<Cat>("咪咪");
    std::shared_ptr<Cat> cat = std::move(unique_cat);
    std::cout << cat->get_name() << std::endl;
    std::cout << "现在的unique_cat:" << unique_cat.get() << std::endl;
    if(!unique_cat) std::cout << "空!" << std:: endl;

    std::shared_ptr<Cat> c = get_unique_ptr();
    if(c){
        c->cat_info();
    }

    return 0;
}