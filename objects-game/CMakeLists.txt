add_executable(ObjectsGame)

target_sources(ObjectsGame
  PRIVATE
    src/main.c
)

target_link_libraries(ObjectsGame
  PRIVATE
    OrsLib
    raylib
)

target_compile_options(ObjectsGame PRIVATE ${PROJECT_WARNING_FLAGS})
