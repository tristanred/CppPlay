cmake_minimum_required(VERSION 4.3)

project(CppPlay)

find_package(ZeroMQ CONFIG REQUIRED)

add_subdirectory(lib-ors)
add_subdirectory(objects-game)
add_subdirectory(ors-server)
