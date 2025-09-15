#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Count{
	public:
	bool operator()(int num){
		return num > 50;
	}
};

int main(void)
{
	vector<int> arr;
	srand(time(nullptr));
	for(int i = 0;i < 100;i++)
			arr.push_back(rand());
	for(int temp : arr)
		cout << temp << ' ';
	int cnt = count_if(arr.begin(),arr.end(),Count());
	cout << "大于50的数有"<< cnt << "个！" << endl;	
	return 0;
}

