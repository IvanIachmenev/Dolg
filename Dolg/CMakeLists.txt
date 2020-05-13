cmake_minimum_required(VERSION 3.15)
project(Dolg)

set(CMAKE_CXX_STANDARD 17)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(Dolg main.cpp map.cpp Player.cpp Engine.cpp Engine.h)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
target_link_libraries(Dolg ${CURSES_LIBRARIES})