#include "cat_cmake.h"
#ifdef cat_h
#include "cat.h"
#endif
#include "unique.h"
int main(void){
    // Cat * cat = new Cat("MyCat");
    // {std::unique_ptr<Cat> new_cat{cat};} //作用域结束就会delete
    // cat->cat_info();
    // new_cat->cat_info();
    // Constructor of Cat :MyCat
    // Destructor of Cat :MyCat
    // 段错误（核心已转储）

    // 不建议这样使用
    // Cat * cat = new Cat("MyCat");
    // std::cout << "--------------------" << std::endl;
    // {std::unique_ptr<Cat> new_cat{cat};} // 在这里就会delete
    // std::cout << "--------------------" << std::endl;
    // cat = nullptr;


    // std::unique_ptr<Cat> cat{new Cat("dd")};
    // cat->cat_info();
    // cat->set_cat_name("咪咪");
    // std::cout << "new" ;
    // cat->cat_info();

    std::unique_ptr<Cat> cat = std::make_unique<Cat>("咪咪");
    cat->cat_info();
    std::cout << "cat的地址:" << cat.get() << std::endl;

    // Cat cat;

    std::unique_ptr<int> arr = std::make_unique<int>(100);
    std::cout << *arr << std::endl;
    std::cout << "int的地址:" << arr.get() << std::endl;
    std::cout << "unque_ptr的地址:" << &arr << std::endl;

    return 0;
}