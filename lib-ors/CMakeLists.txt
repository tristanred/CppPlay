add_library(OrsLib)

target_sources(OrsLib
  PRIVATE
    src/stub.c

  PUBLIC
    FILE_SET myHeaders
    TYPE HEADERS
    BASE_DIRS
      include
    FILES
      include/stub.h
)

target_link_libraries(OrsLib PUBLIC libzmq)
