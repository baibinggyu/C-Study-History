#include <iostream>
#include "cat.h"
#include <memory>

int main(int argc,char* argv[])
{
    std::shared_ptr<int> i_p_1 = std::make_shared<int> (10);
    std::cout << *i_p_1 << std::endl;
    std::cout << i_p_1.use_count() << std::endl;
    std::shared_ptr<int> i_p_2 = i_p_1;
    std::cout << "ptr_count:" << i_p_2.use_count() << std::endl;
    *i_p_2 = 30;
    std::cout << "New Value:" << *i_p_1 << std::endl;
    i_p_1 = nullptr;  //清空不记录use_count
    std::cout <<"NULL:"<< *i_p_2 << std::endl;
    std::shared_ptr<int> i_p_3 = i_p_2;
    std::cout << i_p_3.use_count() << std::endl;


    // 自定义类型!
    std::shared_ptr<Cat> cat = std::make_shared<Cat>("咪咪!");
    cat->cat_info();
    std::cout << cat->get_name() << std::endl;
    std::cout << "程序结束!" << std::endl;

    std::shared_ptr<Cat> cat02 = cat;
    std::cout << cat02->get_name() << std::endl;
    //注意销毁! 只销毁一次
    std::cout << "-----------------" << std::endl;

    std::shared_ptr<Cat> cat03 = cat;

    std::cout << cat03->get_name() << std::endl;
    std::cout << "----------------" << std::endl;

    cat.reset();

    std::cout << "new:"<<  cat03->get_name() << std::endl;


    return 0;   
}