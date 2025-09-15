#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;

void test(void)
{
	vector<int> arr;
	arr.push_back(0);
	arr.push_back(2);
	arr.push_back(0);
	arr.push_back(3);
	arr.push_back(1);
	arr.push_back(4);
	arr.push_back(3);
	arr.push_back(3);
	//查找相邻重复的,依旧迭代器
	vector<int>::iterator it = adjacent_find(arr.begin(),arr.end());
	if(it == arr.end()) cout << "没有找到相邻重复元素!" << endl;
	else cout << "找到相邻重复元素:" << *it << endl;

}
int main(void)
{
	test();
	return 0;
}
