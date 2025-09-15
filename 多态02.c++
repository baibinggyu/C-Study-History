#include <iostream>
class Animal{
    public:
        void speak(void){
            std::cout << "动物在说话!" << std::endl;
     }
};
class Cat : public Animal{
    public:
        void speak(void)  {
            std::cout << "小猫在说话" << std::endl;
        }
};
int main(void)  
{
    Cat cat;
    cat.speak();
    Animal& animal = cat;
    animal.speak();
    return 0;
}