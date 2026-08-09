add_executable(OrsServer)

target_sources(OrsServer
  PRIVATE
    src/stub.c
    src/stub.h
)

target_link_libraries(OrsServer
  PRIVATE
    libzmq
)
