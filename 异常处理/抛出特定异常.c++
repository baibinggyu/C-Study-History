#include <iostream>
using namespace std;
void function()noexcept{
    try{
        throw 1;
    }catch(int value){
        cout <<"int:" << value << endl;
    }catch(char ch){
        cout << "char:" << ch << endl;
    }catch(...){
        cout << "异常有问题!" << endl;
    }
}
int main(void)
{
    function();
    cout << "程序运行:"<< noexcept(function()) << endl;;

    return 0;
}