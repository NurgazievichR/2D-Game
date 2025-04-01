cmake_minimum_required(VERSION 3.10)
project(NovelGame)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(NovelGame main.cpp graphics.cpp handle_input.cpp loading.cpp loading.h)

target_link_libraries(NovelGame sfml-graphics sfml-window sfml-system)

file(COPY ${CMAKE_SOURCE_DIR}/maps DESTINATION ${CMAKE_BINARY_DIR})
file(COPY ${CMAKE_SOURCE_DIR}/media DESTINATION ${CMAKE_BINARY_DIR})
