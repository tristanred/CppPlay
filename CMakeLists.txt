cmake_minimum_required(VERSION 4.3)

project(CppPlay)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_compile_definitions(
  $<$<CONFIG:Debug>:DEBUG>
  $<$<CONFIG:Release>:RELEASE>
)

find_package(ZeroMQ CONFIG REQUIRED)

add_subdirectory(lib-ors)
add_subdirectory(objects-game)
add_subdirectory(ors-server)
