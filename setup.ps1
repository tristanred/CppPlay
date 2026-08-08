#!/usr/bin/env pwsh
# Configure and build the project using the "windows" CMake preset.
# Requires the VCPKG_ROOT environment variable to point at a vcpkg install.

$ErrorActionPreference = "Stop"

cmake --preset windows
cmake --build --preset windows
