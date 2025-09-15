#include <iostream>
#include <vector>
#include <algorithm>
using  namespace std;
class Print{
public:
	void operator()(int num){
		cout << num << ' ';
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
	for_each(arr.begin(),arr.end(),Print());
}
int main(void)
{
	test();
	return 0;
}
