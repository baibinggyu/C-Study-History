#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(void)
{
	vector<int> arr(100);
	fill(arr.begin(),arr.end(),10);
	for_each(arr.begin(),arr.end(),
			[](int temp){cout << temp << ' ' ;});

	return 0;
}
