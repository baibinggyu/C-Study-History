#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	vector<int> arr ;
	for(int i = 0;i < 10;++i)
		arr.push_back(i);
	vector<int> array(arr.size());
	copy(arr.begin(),arr.end(),array.begin());
	cout << "array:";
	for_each(array.begin(),array.end(),
			[](int num){cout << num << ' ';});
	cout << endl;
	return 0; 
}
