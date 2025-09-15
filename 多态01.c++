#include <iostream>
class Animal{
    public:
        virtual void speak(void){
            std::cout << "动物在说话!" << std::endl;
     }
};
class Cat : public Animal{
    public:
        virtual void speak(void) override {
            std::cout << "小猫在说话" << std::endl;
        }
};
class Dog : public Animal{
    public:
        void speak(void){
            std::cout << "小狗在说话!" << std::endl;
        }
};
void doSpeak(Animal& animal)
{
    animal.speak();
}
int main(void)
{
    Cat cat;
    cat.speak();
    Animal& animal = cat;
    animal.speak();
    doSpeak(cat);
    Dog dog;
    dog.speak();
    Animal& animal02 = dog;
    animal02.speak();
    return 0;
}