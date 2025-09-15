#include "cat.h"
Cat::Cat(std::string name):name(name){std::cout << "Constructor of Cat :" << this->name << std::endl;}
void Cat::cat_info() const{std::cout << "名字:" << this->name << std::endl;}
std::string Cat::get_name(void) const{return this->name;}
void Cat::set_cat_name(std::string new_name){
    this->name = new_name;  
}
void Cat::set_friend(std::shared_ptr<Cat> p){this->m_firend = p;}
Cat::~Cat(void){std::cout << "Destructor of Cat :" << name << std::endl;}
