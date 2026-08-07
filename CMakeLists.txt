cmake_minimum_required(VERSION 4.4)

project(SampleLib)

add_library(MyLib)

target_sources(MyLib
  PRIVATE
    mylib/src/stuff.c

  PUBLIC
    FILE_SET myHeaders
    TYPE HEADERS
    BASE_DIRS
      mylib/include
    FILES
      mylib/include/stuff.h
)

add_executable(MyProgram)

target_sources(MyProgram
  PRIVATE
    sample/src/main.c
)

target_link_libraries(MyProgram
  PRIVATE
    MyLib
)
