#include <iostream>
#include <cstring>
#include <string>
using namespace std;
class MyException:public exception{
public:
    explicit MyException(char str[1024]){
        strcpy(this->str,str);
    }
    virtual const char* what() const noexcept override{
        return this->str;
    }
    // 无法捕获异常，因为exception这个父类会提前捕获异常,意思就是说系统的异常会提前抛出
    // virtual const char* what(){
    //     return this->str;
    // }
    ~MyException(){}
private:
    char str[1024] = {0};
};
int main(void)
{

    try{
        throw MyException("继承自标准异常");
    }catch(exception &e){
        cout << e.what() << endl;
    }

    return 0;
}