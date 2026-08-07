
add_executable(SampleGame)

target_sources(SampleGame
  PRIVATE
    src/main.c
)

target_link_libraries(SampleGame
  PRIVATE
    SampleLib
)
