#include <iostream>
using namespace std;
class Test{
public:
    Test(int num):num(num){}
    int what(){
        return this->num;
    }
private:
    int num;
};
int main(void){

    Test num01(10);
    Test num02 = 20; // 会自动的隐式转换
    cout<< "num01:" << num01.what() << endl;
    cout << "num02:"<< num02.what() << endl;
    return 0;
}