cmake_minimum_required(VERSION 4.3)

project(CppPlay C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

add_compile_definitions(
  $<$<CONFIG:Debug>:DEBUG>
  $<$<CONFIG:Release>:RELEASE>
)

set(PROJECT_WARNING_FLAGS
  $<$<C_COMPILER_ID:MSVC>:/W4 /WX>
  $<$<NOT:$<C_COMPILER_ID:MSVC>>:-Wall -Wextra -Werror>
)

find_package(ZeroMQ CONFIG REQUIRED)

add_subdirectory(lib-ors)
add_subdirectory(objects-game)
add_subdirectory(ors-server)
