#include <iostream>
#include<string>
using namespace std;
int main(void)
{
    try{
        // throw 1;
        // throw 'A';
        // throw 3.14f;
        // throw 3ll;
        throw (string)"Hello World!" ;
    }catch(int num){
        cout << "异常为INT:" << num << endl;
    }catch (char ch){
        cout << "异常为char:" << ch << endl; 
    }catch (double d){
        cout << "异常为double:" << d << endl;
    }catch(float f){
        cout << "异常为float:" << f << endl;
    }catch(string str){
        cout << "string的异常:" << str<<endl;
    }catch(...){
        cout << "异常未知" << endl;
    }
    cout << "异常处理完成!" << endl;
    return 0;
}