#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(void)
{
	vector<int> arr01;
	vector<int> arr02;
	for(int i = 0;i < 10;i++)
		{
			arr01.push_back(i);
			arr02.push_back(i + 1);
		}
	vector<int> target(arr01.size() + arr02.size());
	merge(arr01.begin(),arr01.end(),
			arr02.begin(),arr02.end(),
			target.begin());
	cout << "合并之后:"<< endl;
	for_each(target.begin(),target.end(),
			[](int x){cout << x << ' ' << endl;});
	cout << endl;
	return 0;
}
