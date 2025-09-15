#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(void)
{
	vector<int> arr01;
	vector<int> arr02;
	vector<int> target;
	for(int i = 0;i < 10;++i)
	{
		arr01.push_back(i + 1);
		arr02.push_back(i);
	}
	target.resize(min(arr01.size(),arr02.size()));
	vector<int>::iterator itEnd = set_intersection(
			arr01.begin(),arr01.end(),
			arr02.begin(),arr02.end(),
			target.begin());
	for(vector<int>::iterator it = target.begin();it != itEnd;++it)
			cout << *it << ' ' ;
	cout << endl;
		

	return 0;
}
