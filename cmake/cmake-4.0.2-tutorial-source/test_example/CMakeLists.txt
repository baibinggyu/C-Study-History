cmake_minimum_required(VERSION 3.15)
project(TestDemo)

# 创建一个简单的可执行文件
add_executable(Calculator calc.cpp)

# 启用测试
enable_testing()

# 添加一个测试
add_test(NAME Com4 COMMAND Calculator 4)

# 设置测试属性：输出必须包含 "4 is 2"
set_tests_properties(Com4 
    PROPERTIES PASS_REGULAR_EXPRESSION "4 is 2")

# 添加另一个测试
add_test(NAME Com9 COMMAND Calculator 9)
set_tests_properties(Com9 
    PROPERTIES PASS_REGULAR_EXPRESSION "9 is 3") 