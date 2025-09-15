add_library(MathFunctions mysqrt.cxx)

message (STATUS MathFunctions -- ${PROJECT_SOURCE_DIR})

#PUBLIC 本目标需要，依赖这个目标的其他目标也需要
#INTERFACE 本目标不需要，依赖这个目标的其他目标需要
#PRIVATE 本目标需要，依赖这个目标的其他目标不需要
target_include_directories(MathFunctions INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")
message (STATUS "MathFunctions -- ${CMAKE_CURRENT_SOURCE_DIR}") 
