# CppGames

[![Build](https://github.com/tristanred/CppPlay/actions/workflows/build.yml/badge.svg)](https://github.com/tristanred/CppPlay/actions/workflows/build.yml)

Fun repo to stretch out my programming muscle.

Built with good old web searches, reference manuals, tinkering and a lot of head scratching.

## Setup

This project is managed with CMake. You must first configure the project to be able to open it in your favorite editor.

There are several configure presets available, for Windows and Linux. You must use the name of the preset in the cmake command to invoke the preset. Presets are required to invoke the package manager (vcpkg) to acquire the project dependencies. If you don't use a preset, vcpkg will not be invoked.

```bash

# Generates a makefile containing only the Debug config
cmake --preset unix

# Generates a ninja build file for Debug and Release
cmake --preset unix-ninja
```

```powershell
cmake --preset windows
```