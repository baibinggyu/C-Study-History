#include <iostream>
#include <string>
using namespace std;
class MyException:public exception{
    public:
    explicit MyException(string str){
        this->str = str;
    }
    virtual const char* what() const noexcept override{
        return str.c_str();
    }
    ~MyException(){};
    private:
        string str;
};
int main(void)
{
    try{
        throw MyException("这是string的异常");
    }catch(exception &e){
        cout << e.what() << endl;
    }
    return 0;
}