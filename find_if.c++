#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Condition{
	public:
		bool operator()(int num){
			return num > 30 ? true : false; 
		}
};

void test(void)
{
	vector<int> arr;
	arr.push_back(10);
	arr.push_back(20);
	arr.push_back(30);
	arr.push_back(40);
	arr.push_back(50);
	vector<int>::iterator it =  find_if(arr.begin(),arr.end(),Condition());
	//返回第一个match的元素
	while(it != arr.end())
			cout << *it++ << ' ';
	cout << endl;
}

int main(void)
{
	test();
	return 0;
}
