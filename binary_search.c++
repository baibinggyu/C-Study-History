#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{	
	vector<int> arr;
	for(int i = 0;i < 100;++i)
		arr.push_back(i);
	cout << "正在查找1~99中是否存在50" << endl;
	if(binary_search(arr.begin(),arr.end(),50))
			cout << "1～99中存在50" << endl;
	else cout << "未寻找到!" << endl;


	return 0;
}
