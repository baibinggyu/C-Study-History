#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
using namespace std;
int main(void)
{
	srand((unsigned int )time(nullptr));
	vector<int> arr;
	for(int i = 0;i < 10;i++)
		arr.push_back(i);
	random_shuffle(arr.begin(),arr.end());
	for_each(arr.begin(),arr.end(),[](int num){cout << num << ' ' << endl;});		
	return 0;
}
