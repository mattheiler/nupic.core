# nupic.core-redux
Nupic.Core C++ Extraction Redux.

## Quick Start

### Windows

#### Setup

* [CMake](https://cmake.org/download/)
* [VCPKG](https://github.com/Microsoft/vcpkg#quick-start)
* [CapnProto](https://capnproto.org/install.html)

#### Install

* Run `vcpkg install apr`.
* Run `vcpkg install apr-util`.
* Run `vcpkg install boost`.
* Run `vcpkg install yaml-cpp`.
* Run `vcpkg install zlib`.
* Build the CapnProto `INSTALL` project.  

#### CMake
* __CONFIGURE__
  * Specify the generator for this project: __Visual Studio 15 2017__
  * Specify toolchain file for cross-compiling: __~\vcpkg\scripts\buildsystems\vcpkg.cmake__
* __GENERATE__
