#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(void)
{
	vector<int> arr;
	arr.push_back(20);
	arr.push_back(20);
	arr.push_back(30);
	arr.push_back(20);
	cout << "old_arr:";
	for(int temp : arr) cout << temp << ' ' ;
	cout << endl;
	cout << "new_arr(replace 20 --> 2000):";
	replace(arr.begin(),arr.end(),20,2000);
	for_each(arr.begin(),arr.end(),
			[](int temp){cout << temp << ' ';});
	cout << endl;

	return 0;
}
