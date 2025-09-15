#include <iostream>
#include <functional>
#include <map>
int add(int a,int b) {return a + b;}
int sub(int a,int b){return a - b;}
void func(std::function<int(int,int)> f,int x,int y){
    std::cout << f(x,y) << std::endl;  
}

int main(void){
    std::function<int(int,int)> p = add;
    std::cout << "1 + 2 = " << p(1,2) << std::endl;
    p = sub;
    std::cout << "1 - 2 = " << p(1,2) << std::endl;
    func(sub,999,99);

    std::map<std::string,std::function<int(int,int)>> map{{"+",add},{"-",sub},{"*",[](int a,int b)->int{return a * b;}}};
    std::cout << "map:" << map["+"](2,3) << std::endl;
    std::cout << "2 * 3 = " << map["*"](2,3) << std::endl;


    return 0;
}