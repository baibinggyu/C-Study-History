cmake_minimum_required(VERSION 3.15)
project(CompilerFlagsDemo)

# 1. 创建"规则手册"
add_library(my_compiler_flags INTERFACE)
# 规则1：使用C++11
target_compile_features(my_compiler_flags INTERFACE cxx_std_11)
# 规则2：开启警告
target_compile_options(my_compiler_flags INTERFACE -Wall -Wextra)

# 2. 创建一个可执行文件
add_executable(MyProgram main.cpp)

# 3. 让可执行文件遵守规则手册
target_link_libraries(MyProgram PRIVATE my_compiler_flags)

# 输出一些信息帮助我们理解
get_target_property(flags MyProgram COMPILE_OPTIONS)
message(STATUS "MyProgram 的编译选项: ${flags}")

get_target_property(features MyProgram COMPILE_FEATURES)
message(STATUS "MyProgram 的编译特性: ${features}") 