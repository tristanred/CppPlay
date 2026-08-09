
add_executable(ObjectsGame)

target_sources(ObjectsGame
  PRIVATE
    src/stub.c
    src/stub.h
)

find_package(raylib CONFIG REQUIRED)

target_link_libraries(ObjectsGame
  PRIVATE
    OrsLib
    raylib
)
