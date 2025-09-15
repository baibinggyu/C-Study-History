#ifndef MENU_H

#define MENU_H


#include <iostream>
class Menu{
public:
   Menu(void);
   static void display(void);
   bool quit(void);
   ~Menu(void);
};

#endif