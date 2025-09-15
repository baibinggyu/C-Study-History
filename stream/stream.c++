#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int main(void){
    stringstream ss("Hello world!");
    string str = "占位";
    ss << str;
    string line;
    getline(ss,line);
    cout << line << endl;
    
    return 0;
}