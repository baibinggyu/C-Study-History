#include <iostream>
class MyClass{
public:
	inline static int myValue;
};

// int MyClass::myValue = 0;

int main(void)
{
	std::cout << MyClass::myValue << std::endl;
	return 0;
}
