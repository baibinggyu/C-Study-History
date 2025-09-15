#include <iostream>
#include <functional>
using namespace std;
void test(void){
	negate<int> num;
	cout << num(50) << endl;
}
int main(void)
{
	test();
	return  0;
}
