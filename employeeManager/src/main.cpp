#include <fstream>
#include <iostream>
#include <ostream>
#include <vector>

#include "employee.h"
void test(void);
int main() {
    test();
    return 0;
}
// void test() {
//     std::ifstream ifs ("managers.csv",std::ios::in);
//     if (!ifs.is_open()) {cerr << "FILE OPEN FAILED!" << endl; exit(-1);}
//     vector<Data> data =  FileRead(ifs);
//     FilePrint(data);
//     FileWrite(data);
// }
void test(void) {
    Menu::display();
}

