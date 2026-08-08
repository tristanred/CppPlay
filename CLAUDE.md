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
(`CMakePresets.json`). All presets require the `VCPKG_ROOT` environment variable to point
at a vcpkg installation.

- `windows` — MSVC + vcpkg toolchain (Visual Studio generator, multi-config). Build preset
  `windows` builds Debug, `windows-release` builds Release.
- `unix` — macOS/Linux, vcpkg toolchain, Unix Makefiles generator (single-config, Debug
  only). The default/simplest way to build on macOS/Linux; `setup.sh` uses `unix-ninja`
  instead (see below).
- `unix-ninja` — macOS/Linux, vcpkg toolchain, Ninja Multi-Config generator (requires
  `ninja` on PATH). Build preset `unix-ninja` builds Debug, `unix-ninja-release` builds
  Release. Used by `setup.sh` and by CI (to cover both Debug and Release on Linux/macOS).

Build output goes to `out/build/<preset-name>/` (gitignored).

Common commands:

```bash
# Configure (first time, or after changing CMakeLists.txt/vcpkg.json)
cmake --preset windows   # or: cmake --preset unix   # or: cmake --preset unix-ninja

# Build
cmake --build --preset windows   # or: cmake --build --preset unix   # or: cmake --build --preset unix-ninja
```

There are no test targets configured yet, and no lint step defined — the project is early-stage.

Dependency versions are pinned via vcpkg's manifest mode (`vcpkg.json`, with a
`builtin-baseline` commit hash).

When adding a new sample program or library, follow the existing pattern: a subdirectory with
its own `CMakeLists.txt`, added to the root `CMakeLists.txt` via `add_subdirectory`.
