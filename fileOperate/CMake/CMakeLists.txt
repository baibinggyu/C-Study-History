cmake_minimum_required(VERSION 3.25.1)
project(main VERSION 2.11)
set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED false) # 标准是否为必须 参数 on off true false
add_executable(main main.cxx)
# target_include_directories(employeeManager head)
message(STATUS "Hello World!")
message(STATUS "${PROJECT_BINARY_DIR}") 
message(STATUS "${main_VERSION_MAJOR}")
message(STATUS "${main_VERSION_MINOR}")
set(STR_TEST "Hello World!")

target_include_directories(main PUBLIC ${PROJECT_BINARY_DIR})

configure_file(mainConfig_file.h.in mainConfig_file.h)
