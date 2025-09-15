#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class transForm{
	public:
		int operator()(int num){
			return num * 2;
		}
};
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
	vector<int> res(arr.size(),0);
	transform(arr.begin(),arr.end(),res.begin(),transForm());
	cout << "arr:" << ' ';
	for_each(arr.begin(),arr.end(),Print());
	cout << endl;
	cout << "-----------------------------"<< endl;
	cout << "res:" << ' ';
	for_each(res.begin(),res.end(),Print());
	cout << endl;

}

int main(void)
{
	test();
	return 0;
}

