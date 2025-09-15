#include <iostream>
using namespace std;
class Person{
public:
    int m = 10;
    int n = 20;
};
ostream& operator+(ostream& cout,const Person& p)
{   
    cout << p.m << ' '  << p.n << std::endl;
    return cout;
}

int main(void){

    Person p;
    cout + p + p + p + p;
    return 0;
}