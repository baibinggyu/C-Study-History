#include <iostream>
#include <string>
using namespace std;
class BaseClass{
    public:
    virtual void printError(){}
};
class OutOfRange:public BaseClass{
    public:
    virtual void printError(){
        cout << "越界异常!" << endl;
    }
};
int main(void)
{
    OutOfRange outofrange;
    try
    {
        throw outofrange;
    }
    catch(BaseClass &e)
    {
        e.printError();
    }
    
    return 0;
}