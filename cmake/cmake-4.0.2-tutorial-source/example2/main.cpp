#include <iostream>
#include <vector>

int main() {
    // 使用 C++11 的 auto 和范围 for
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    
    // 这里使用了 C++11 特性
    for(const auto& num : numbers) {
        std::cout << num << " ";
    }
    
    // 未使用的变量（会触发警告）
    int unused = 42;
    
    return 0;
} 