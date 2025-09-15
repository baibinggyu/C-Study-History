#include "menu.h"
#include "../include/menu.h"

Menu::Menu(void){}
void Menu::display(void) {
        std::cout << "          欢迎使用employeeManager系统!" << std::endl;
        std::cout << "      以下是功能菜单，请输入相应的数字即可使用!" << std::endl;

    }
bool Menu::quit(void){return true;}
Menu::~Menu(void){}