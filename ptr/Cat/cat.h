#ifndef CAT_H
#define CAT_H
#include <string>
#include <iostream>
#include <memory>
class Cat{
public:
    Cat(std::string name);
    Cat(void) = default;
    ~Cat(void);
    void cat_info() const;
    std::string get_name(void) const;
    void set_cat_name(std::string new_name);
    void set_friend(std::shared_ptr<Cat> p);
private:
    std::string name{"Mimi"};
    std::weak_ptr<Cat> m_firend;
};
#endif