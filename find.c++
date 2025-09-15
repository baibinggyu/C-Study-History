#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;
void test(void)
{
	vector<int> arr;
	arr.push_back(10);
	arr.push_back(20);
	arr.push_back(30);
	arr.push_back(40);
	vector<int>::iterator it = find(arr.begin(),arr.end(),20);
	if(it == arr.end()) cout << "未找到" << endl;
	else cout << "找到了:"<<*it << endl;
}
int main(void)
{
	test();
	return 0;
}
