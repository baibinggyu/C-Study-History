#include <iostream>
#include <fstream>
using namespace std;
int main(void){ 
    fstream fs("test.txt",std::ios::in);
    if(!fs.is_open()){cout << "FILE FAILED ERROR" << endl; return -1;}
    while(!fs.eof()){
        string str;
        getline(fs,str);
        cout << str;
    }
    return 0;
}