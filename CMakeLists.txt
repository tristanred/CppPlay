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

# raylib is built from source rather than via vcpkg: vcpkg's raylib port
# (which links against an external vcpkg-built glfw3) creates a window that
# never becomes visible on macOS, even though the same raylib source builds
# and runs correctly with its own bundled GLFW. Building from source uses
# raylib's bundled GLFW and avoids the issue.
include(FetchContent)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
FetchContent_Declare(
  raylib
  GIT_REPOSITORY https://github.com/raysan5/raylib.git
  GIT_TAG 6.0
  GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(raylib)

add_subdirectory(lib-ors)
add_subdirectory(objects-game)
add_subdirectory(ors-server)
