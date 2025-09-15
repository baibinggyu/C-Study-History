#include <iostream> 
#include "cat.h"
#include <memory>
void cat_by_value(std::shared_ptr<Cat> cat){
    std::cout << cat->get_name() << std::endl;
    cat->set_cat_name("函数内设置的名字!");
    std::cout << "function use_count:" << cat.use_count() << std::endl;
}
void cat_by_ref(std::shared_ptr<Cat>& cat){
    std::cout << cat->get_name() << std::endl;
    cat->set_cat_name("函数内设置的名字!");
    std::cout << "function use_count:" << cat.use_count() << std::endl;
}
int main(void){
    std::shared_ptr<Cat> cat = std::make_shared<Cat>("咪咪"); 
    std::cout << "函数外use_count!:" << cat.use_count() << std::endl;
    cat_by_value(cat);
    std::cout << "函数后use_count!:" << cat.use_count() << std::endl;


    return 0;
}