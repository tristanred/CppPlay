#!/usr/bin/env bash
# Configure and build the project using the "unix" CMake preset.
# Requires the VCPKG_ROOT environment variable to point at a vcpkg install.
set -euo pipefail

cmake --preset unix
cmake --build --preset unix
