#include <iostream>
#include <sstream>
using namespace std;
int main(void){
    // 可以拼接
    ostringstream oss;
    oss << "姓名:" << "白玉" << endl
    << "年龄:" << 18 << endl;
    cout << oss.str() ;

    return 0;
}