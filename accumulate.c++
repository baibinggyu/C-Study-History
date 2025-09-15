#include <iostream>
#include <numeric>
using namespace std;
#include <vector>
int main(void)
{
	//计算总和
	vector<int> arr;
	for(int i = 0;i < 100;i++) arr.push_back(i);
	cout << "50~99的和" << accumulate(arr.begin(),arr.end(),50) << endl;
	
	return 0;
}
