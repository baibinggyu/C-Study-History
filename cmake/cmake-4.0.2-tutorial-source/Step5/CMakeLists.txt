cmake_minimum_required(VERSION 3.15)

# 设置项目名称和版本
project(Tutorial VERSION 1.0)

# 指定 C++ 标准
add_library(tutorial_compiler_flags INTERFACE)
target_compile_features(tutorial_compiler_flags INTERFACE cxx_std_11)

# 仅在构建此项目时通过 BUILD_INTERFACE genex 添加编译器警告标志
set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")
target_compile_options(tutorial_compiler_flags INTERFACE
  "$<${gcc_like_cxx}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>>"
  "$<${msvc_cxx}:$<BUILD_INTERFACE:-W3>>"
)

# 配置头文件以将一些 CMake 设置传递给源代码
configure_file(TutorialConfig.h.in TutorialConfig.h)

# 添加 MathFunctions 库
add_subdirectory(MathFunctions)

# 添加可执行文件
add_executable(Tutorial tutorial.cxx)

target_link_libraries(Tutorial PUBLIC MathFunctions tutorial_compiler_flags)

# 将二进制目录添加到包含文件的搜索路径中
# 这样我们就能找到 TutorialConfig.h
target_include_directories(Tutorial PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )

# TODO 3: 将 Tutorial 安装到 bin 目录
# 提示：使用 TARGETS 和 DESTINATION 参数
# TARGETS 参数用于指定要安装的目标(比如可执行文件或库)
# 这里 Tutorial 是我们之前用 add_executable() 创建的可执行文件目标
# install(TARGETS ...) 会安装这个目标文件以及它的所有依赖
# message(STATUS "默认安装路径 : ${CMAKE_INSTALL_PREFIX}")
install(TARGETS Tutorial DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/build)

# TODO 4: 将 TutorialConfig.h 安装到 include 目录
# 提示：使用 FILES 和 DESTINATION 参数
install(FILES "${CMAKE_BINARY_DIR}/TutorialConfig.h" DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/build/include )
# TODO 5: 启用测试
enable_testing()
# TODO 6: 添加一个名为 Runs 的测试，运行以下命令：
# $ Tutorial 25
add_test(NAME Runs COMMAND Tutorial 25)

# TODO 7: 添加一个名为 Usage 的测试，运行以下命令：
# $ Tutorial
# 确保显示预期的输出
# 提示：使用带有 "Usage.*number" 的 PASS_REGULAR_EXPRESSION 属性
add_test(NAME Usage COMMAND Tutorial)
set_tests_properties(Usage PROPERTIES PASS_REGULAR_EXPRESSION "Usage.*number")
# TODO 8: 添加一个运行以下命令的测试：
# $ Tutorial 4
# 确保结果正确
# 提示：使用带有 "4 is 2" 的 PASS_REGULAR_EXPRESSION 属性
add_test(NAME Com4 COMMAND Tutorial 4)
set_tests_properties(Com4 PROPERTIES PASS_REGULAR_EXPRESSION "4 is 2")

# TODO 9: 添加更多测试。创建一个名为 do_test 的函数以避免复制粘贴。
# 测试以下值：4、9、5、7、25、-25 和 0.0001

function(do_test num res)
  add_test(NAME Comp${num} COMMAND Tutorial ${num})
  set_tests_properties(Comp${num} PROPERTIES PASS_REGULAR_EXPRESSION ${res})
endfunction()
do_test(4 "4 is 2")
do_test(9 "9 is 3")
do_test(5 "5 is 2.236")
do_test(7 "7 is 2.645")
do_test(25 "25 is 5")
do_test(-25 "(-nan|nan|0)")
do_test(0.0001 "0.0001 is 0.01")

