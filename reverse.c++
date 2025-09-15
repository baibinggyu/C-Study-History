#include <iostream>
#include <string>	
#include <cstring>
#include <algorithm>
using namespace std;

int main(void)
{
	int n = 10;
	string str = to_string(n);
	reverse(str.begin(),str.end());
	cout << "New_Str:" << str << endl;
	return 0;
}
