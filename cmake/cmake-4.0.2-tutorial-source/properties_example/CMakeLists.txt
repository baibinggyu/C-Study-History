cmake_minimum_required(VERSION 3.15)
project(PropertiesDemo)

# 创建可执行文件
add_executable(MyApp main.cpp)

# 设置目标属性
set_target_properties(MyApp PROPERTIES
    # 输出文件名
    OUTPUT_NAME "my_application"
    # Debug版本加后缀_d
    DEBUG_POSTFIX "_d"
    # 运行时输出目录
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

# 设置源文件属性
set_source_files_properties(main.cpp PROPERTIES
    # 添加编译标志
    COMPILE_FLAGS "-Wall"
    # 指定语言
    LANGUAGE CXX
)

# 启用测试
enable_testing()

# 添加测试
add_test(NAME AppTest COMMAND MyApp)

# 设置测试属性
set_tests_properties(AppTest PROPERTIES
    # 测试超时时间（秒）
    TIMEOUT 30
    # 测试通过的条件
    PASS_REGULAR_EXPRESSION "Hello, World!"
    # 测试失败的条件
    FAIL_REGULAR_EXPRESSION "Error"
    # 测试的工作目录
    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
) 