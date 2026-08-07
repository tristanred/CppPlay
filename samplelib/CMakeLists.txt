add_library(SampleLib)

target_sources(SampleLib
  PRIVATE
    src/stuff.c

  PUBLIC
    FILE_SET myHeaders
    TYPE HEADERS
    BASE_DIRS
      include
    FILES
      include/stuff.h
)
