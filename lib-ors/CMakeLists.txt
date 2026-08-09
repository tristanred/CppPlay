add_library(OrsLib)

target_sources(OrsLib
  PRIVATE
    src/log.c

  PUBLIC
    FILE_SET myHeaders
    TYPE HEADERS
    BASE_DIRS
      include
    FILES
      include/log.h
)

target_link_libraries(OrsLib PUBLIC libzmq)
