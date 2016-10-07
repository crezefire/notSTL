#notSTL: Cross Platform & Compiler STL

Plain old STL, configurable, measurable.

Supported Platforms:
- Windows (Visual Studio)
- Linux (Makefiles, Visual Studio Code)
- Linux via Windows (Planned)

##Table of Contents
- [Overview](#overview)
- [Requirements](#requirements)
- [Getting Started](#getting-started)

##Overview
........

##Requirements
Common:
- [CMake](https://cmake.org/download/) >= 3.4
- bash (On Windows use MinGW installed via [Git for Windows](https://git-scm.com/downloads))

Windows:
- [Visual Studio](https://www.visualstudio.com/en-us/downloads/download-visual-studio-vs.aspx)

Linux:
- GCC or [Clang](http://llvm.org/releases/)
- [Visual Studio Code](https://code.visualstudio.com/download) (Optional, Requires GCC + GDB)
- [VSCode C++ Extension](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools) (Optional, Required with VSCode)

##Getting Started
To build the project as is run:

```shell
./create.sh
```
This script detects which OS you are running and runs the default CMake project generate command. It supports the following flags:
- `-h|--help` to print help
- `-f|--folder=<folder>` name of the folder to store build files. **Default: build**
- `-G="Generator Name"` for custom generator. **Default: "Visual Studio 14 Win64" or "Unix Makefiles"**
- `-m|--make=<extra CMake params>` Eg: `-m='-DVAR_SETUP=1 -DVAR2_SETUP=0`

Linux only:
- `-b|--build=<build type>` CMake build type. **Default: Debug**
- `-c|--clang` Uses the Clang compiler instead of GCC. **Default: Don't use Clang**
- `-v|--vscode` Skip setting up VSCode configs. **Default: Setup VSCode configs**

Note: Using Clang will still show CMake as setting up GCC but it will definitely be using Clang
