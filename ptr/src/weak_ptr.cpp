#include <iostream>
#include <memory>
#include "cat.h"
int main(void)
{
    // weak_ptr 不能* he ->
    std::shared_ptr<Cat> cat = std::make_shared<Cat>("咪咪");
    std::weak_ptr<Cat> weak(cat);
    std:: cout << "cat_use_count:" << cat.use_count() << std::endl; // 依旧是1
    std::cout << "weak_use_count:" << weak.use_count() << std::endl; // 也是1
    //会报错
    // weak->cat_info();

     // 提升权限
     weak.lock()->cat_info();

    // 处理循环依赖问题
    std::shared_ptr<Cat> c1 = std::make_shared<Cat>("c1");
    std::shared_ptr<Cat> c2 = std::make_shared<Cat>("c2");
    c1->set_friend(c2);
    c2->set_friend(c1);


   
    return 0;
}