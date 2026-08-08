#!/usr/bin/env bash
# Configure and build the project using the "unix-ninja" CMake preset.
# Requires the VCPKG_ROOT environment variable to point at a vcpkg install,
# and Ninja (Ninja Multi-Config generator) available on PATH.
set -euo pipefail

cmake --preset unix-ninja
cmake --build --preset unix-ninja
