cmake_minimum_required(VERSION 3.15)
project(InstallDemo)

# 创建一个简单的可执行文件
add_executable(MyProgram main.cpp)

# 正确的方式：使用 TARGETS
install(TARGETS MyProgram 
        DESTINATION bin)

# 不推荐的方式：使用 FILES
install(FILES "${CMAKE_BINARY_DIR}/MyProgram"
        DESTINATION bin_files
        PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ
                    GROUP_EXECUTE GROUP_READ
                    WORLD_EXECUTE WORLD_READ)

# 文件安装的正确用途：安装配置文件、头文件等
install(FILES "config.txt" "README.md"
        DESTINATION share) 