#!/usr/bin/env bash
# Configure and build the project using the "unix" CMake preset.
set -euo pipefail

cmake --preset unix
cmake --build --preset unix
