# Pong (SFML + CMake)

Pong — a simple arcade-style game implemented in C++ using SFML and built with CMake.

Short description
- A classic Pong game implemented with SFML.
- Built as a lightweight C++ project with CMake support so it works across major platforms.

## Screenshots

![Gameplay Screenshot 2](https://github.com/user-attachments/assets/37e169fb-b924-4b08-a749-404fa740a48e)

## Features

- Two-player local gameplay
- Score tracking
- Configurable window size (via CMake or in-game settings if implemented)
- Cross-platform: Linux, Windows, macOS (when SFML is supported)

## Requirements

- CMake (>= 3.15 recommended)
- A C++17-compatible compiler (GCC, Clang, MSVC)
- Internet connection for FetchContent (the CMake setup bundled with this template downloads SFML automatically)
- On Linux, SFML runtime dependencies (see below)

## Linux dependencies (example for Debian/Ubuntu)

Install system dependencies required by SFML:
```bash
sudo apt update
sudo apt install \
    libxrandr-dev \
    libxcursor-dev \
    libxi-dev \
    libudev-dev \
    libfreetype-dev \
    libflac-dev \
    libvorbis-dev \
    libgl1-mesa-dev \
    libegl1-mesa-dev
```

## Build (command line)

From the project root:

```bash
# Create and configure the build directory
cmake -B build

# Build the project
cmake --build build --config Release
```

Notes:
- On multi-configuration generators (Visual Studio) you may need `--config Release` or change configuration in the IDE.
- To force a generator:
  cmake -B build -G "Ninja"

## Visual Studio

- Open the project folder in Visual Studio (CMake will configure automatically) or use the CMakeLists.txt to generate a solution.
- Make sure the required C++ workload and CMake tools are installed in Visual Studio.

## Run

After building, the executable will be located in the build output directory. For example:

```bash
# On Linux/macOS
./build/<executable-name>

# On Windows (PowerShell)
.\build\<configuration>\<executable-name>.exe
```

Replace `<executable-name>` with the target name defined in CMakeLists.txt (rename it there if desired).

## Controls

- Paddle movement: Left/Right arrows 
- Pause: Esc 

## Customizing SFML version

This project uses CMake FetchContent to obtain and build SFML alongside the project. To change the SFML version, edit the `GIT_TAG` in the `CMakeLists.txt` FetchContent call.

