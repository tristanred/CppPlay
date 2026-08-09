add_executable(OrsServer)

target_sources(OrsServer
  PRIVATE
    src/stub.c
)

target_link_libraries(OrsServer
  PRIVATE
    libzmq
)

target_compile_options(OrsServer PRIVATE ${PROJECT_WARNING_FLAGS})
