#include <iostream>

int main() {
    // 这会触发未使用变量的警告
    int unused_variable = 42;
    
    std::cout << "Hello, World!" << std::endl;
    return 0;
} 