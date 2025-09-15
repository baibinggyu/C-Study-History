#include <string>

// 这个函数有潜在的阴影变量警告
void process_data(int data) {
    for(int data = 0; data < 10; ++data) {  // 变量名重复会触发 -Wshadow 警告
        // do something
    }
} 