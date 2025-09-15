// 一个简单的程序，用于计算一个数的平方根
#include <cmath>
#include <cstdlib> // TODO 5: 删除这一行
#include <iostream>
#include <string>

// TODO 11: 包含 TutorialConfig.h

int main(int argc, char* argv[])
{
  if (argc < 2) {
    // TODO 12: 使用 Tutorial_VERSION_MAJOR 和 Tutorial_VERSION_MINOR 创建一个打印语句
    std::cout << "Usage: " << argv[0] << " number" << std::endl;
    return 1;
  }

  // 将输入转换为 double 类型
  // TODO 4: 用 std::stod(argv[1]) 替换 atof(argv[1])
  double const inputValue = atof(argv[1]);

  // 计算平方根
  double const outputValue = sqrt(inputValue);
  std::cout << "The square root of " << inputValue << " is " << outputValue
            << std::endl;
  return 0;
}
