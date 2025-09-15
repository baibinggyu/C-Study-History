cmake_minimum_required(VERSION 3.25.1)
project(employee VERSION 1.0)

set(SDL2 "${CMAKE_CURRENT_SOURCE_DIR}/SDL2/lib/libSDL2.a")
message(STATUS "SDL2 = ${SDL2}")

set(SDL2main "${CMAKE_CURRENT_SOURCE_DIR}/SDL2/lib/libSDL2main.a")
message(STATUS "SDL2main = ${SDL2main}")

set(SDL2_image "${CMAKE_CURRENT_SOURCE_DIR}/SDL2/lib/libSDL2_image.so")
message(STATUS "SDL2_image = ${SDL2_image}")

set(SDL2_mixer "${CMAKE_CURRENT_SOURCE_DIR}/SDL2/lib/libSDL2_mixer.so")
message(STATUS "SDL2_mixer = ${SDL2_mixer}")

set(SDL2_ttf "${CMAKE_CURRENT_SOURCE_DIR}/SDL2/lib/libSDL2_ttf.so")
message(STATUS "SDL2_ttf = ${SDL2_ttf}")

set(INCLUDE "${CMAKE_CURRENT_SOURCE_DIR}/include")
message(STATUS "INCLUDE ${INCLUDE}")

file(GLOB SOURCE "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
message(STATUS "SOURCE = ${SOURCE}")

add_executable(employee  ${SOURCE})
target_link_libraries(employee PRIVATE ${SDL2main} ${SDL2} ${SDL2_image} ${SDL2_mixer} ${SDL2_ttf} )
target_include_directories(employee PRIVATE "${INCLUDE}")
