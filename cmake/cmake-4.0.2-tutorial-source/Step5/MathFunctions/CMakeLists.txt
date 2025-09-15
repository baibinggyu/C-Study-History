add_library(MathFunctions MathFunctions.cxx)

# 声明任何链接到我们的人都需要包含当前源目录
# 以找到 MathFunctions.h，而我们自己不需要
target_include_directories(MathFunctions
                           INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
                           )

# 我们是否应该使用自己的数学函数
option(USE_MYMATH "使用教程提供的数学实现" ON)
if (USE_MYMATH)
  target_compile_definitions(MathFunctions PRIVATE "USE_MYMATH")

  # 仅实现 sqrt 的库
  add_library(SqrtLibrary STATIC
              mysqrt.cxx
              )

  # 将 SqrtLibrary 链接到 tutorial_compiler_flags
  target_link_libraries(SqrtLibrary PUBLIC tutorial_compiler_flags)

  target_link_libraries(MathFunctions PRIVATE SqrtLibrary)
endif()

# 将 MathFunctions 链接到 tutorial_compiler_flags
target_link_libraries(MathFunctions PUBLIC tutorial_compiler_flags)

# TODO 1: 创建一个名为 installable_libs 的变量，它是我们想要安装的所有库的列表
# （例如 MathFunctions 和 tutorial_compiler_flags）
# 然后将可安装的库安装到 lib 文件夹
# 提示：使用 TARGETS 和 DESTINATION 参数
set(installable_libs MathFunctions tutorial_compiler_flags)
install(TARGETS ${installable_libs} DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/../build/lib)

# TODO 2: 将库的头文件安装到 include 文件夹
# 提示：使用 FILES 和 DESTINATION 参数
install(FILES MathFunctions.h DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/../build/include)