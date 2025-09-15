#include <iostream>
using namespace std;
#include <functional>
#include <vector>
void test(void)
{
	plus<int> pul;
	cout << pul(10,20) << endl;
}
int main(void)
{
	test();
	return	0;
}
