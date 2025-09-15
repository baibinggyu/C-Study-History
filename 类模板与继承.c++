#include <iostream>
//继承的时候要声明T的类型,不然不能分配内存
//灵活指定父类的T类型，子类也要变成模板
template<class T>
class Base{
    public:
        Base(T num) : m(num){}
        T m;
};
class Son :public Base<int>
{
    public:
        Son(int val): Base<int>(val){}
        int n = m;
};
template<class T1, class T2>
class Son2 : public Base<T2>
{
    public:
        Son2(T1 temp01,T2 temp02):Base<T2>(temp02),obj(temp01){};
        void showSon2(void){
            std::cout << "This is Son2:" << obj << ' ' << this->m << std::endl;
            // 如果父类 Base<T2> 的类型 T2 尚未确定（即依赖模板参数）
            // 编译器无法确定 m 是否来自父类（可能被特化覆盖）
            // 默认不会去父类作用域查找「依赖名称」
            //所以要加上this
        }
        T1 obj; 
};
void test(void){
    Son2<int,char> s(10,'a');
    s.showSon2();
}
int main(void)
{
    test();
    return 0;
}