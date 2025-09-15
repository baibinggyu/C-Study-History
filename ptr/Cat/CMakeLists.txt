add_library(Cat cat.cpp)
message(STATUS "cat ----- ${PROJECT_SOURCE_DIR}/cat.cpp")
target_include_directories(Cat PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
message(STATUS "cat.h ----- ${PROJECT_SOURCE_DIR}")s