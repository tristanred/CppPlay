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

# Package managers that generate a CMake config (e.g. vcpkg, Conan) provide
# this target directly. Homebrew and most Linux distro packages don't, so
# fall back to locating the library/header ourselves via the system's
# default search paths (no hardcoded prefixes).
find_package(ZeroMQ CONFIG QUIET)

if(NOT TARGET libzmq AND NOT TARGET ZeroMQ::ZeroMQ)
  find_library(ZeroMQ_LIBRARY NAMES zmq libzmq REQUIRED)
  find_path(ZeroMQ_INCLUDE_DIR NAMES zmq.h REQUIRED)

  add_library(ZeroMQ::ZeroMQ UNKNOWN IMPORTED)
  set_target_properties(ZeroMQ::ZeroMQ PROPERTIES
    IMPORTED_LOCATION "${ZeroMQ_LIBRARY}"
    INTERFACE_INCLUDE_DIRECTORIES "${ZeroMQ_INCLUDE_DIR}")
elseif(TARGET libzmq AND NOT TARGET ZeroMQ::ZeroMQ)
  # vcpkg's ZeroMQConfig.cmake exports the "libzmq" target name.
  add_library(ZeroMQ::ZeroMQ ALIAS libzmq)
endif()

target_link_libraries(SampleLib PUBLIC ZeroMQ::ZeroMQ)