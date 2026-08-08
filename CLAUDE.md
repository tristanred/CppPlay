# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Purpose of this repo

This is a personal hobby project for practicing C/C++ programming. The stated goal is to
play and practice low-level programming skills.

## Code authorship rule (read this first)

**Do not write or modify application source code (`.c`, `.h`, `.cpp`, `.hpp`, etc.) in this
repo unless the user explicitly asks you to and confirms it.** The point of this project is
for the user to write the code themselves without AI assistance.

- If asked to implement a feature or fix a bug in the code, do **not** edit the source files.
  Instead, explain the approach, point to relevant docs/APIs, and offer example snippets
  in your response — without applying them to the repo.
- Everything *not* code is fair game to edit freely: CMake build files, `vcpkg.json`,
  CI/CD configuration, editor/tooling config (`.vscode/`, `CMakePresets.json`), `README.md`,
  `.gitignore`, etc.
- If unsure whether something counts as "code" for this rule, ask.

## Build system

CMake with a vcpkg manifest (`vcpkg.json`) for dependencies, driven via CMake Presets
(`CMakePresets.json`). Two configure/build presets are defined:

- `windows` — MSVC + vcpkg toolchain. Requires the `VCPKG_ROOT` environment variable to
  point at a vcpkg installation.
- `unix` — macOS/Linux, uses the system package manager (Homebrew/apt) instead of vcpkg,
  Debug build type, Unix Makefiles generator.

Build output goes to `out/build/<preset-name>/` (gitignored).

Common commands:

```bash
# Configure (first time, or after changing CMakeLists.txt/vcpkg.json)
cmake --preset windows   # or: cmake --preset unix

# Build
cmake --build --preset windows   # or: cmake --build --preset unix
```

There are no test targets configured yet, and no lint step defined — the project is early-stage.

Dependency versions are pinned via vcpkg's manifest mode (`vcpkg.json`, with a
`builtin-baseline` commit hash).

When adding a new sample program or library, follow the existing pattern: a subdirectory with
its own `CMakeLists.txt`, added to the root `CMakeLists.txt` via `add_subdirectory`.
