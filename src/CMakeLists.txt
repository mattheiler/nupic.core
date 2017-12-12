# CMake
cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

# Targets
# TODO Preferences based on generator? ...Overkill?
SET(NUPIC_BINDINGS_GROUP_PREFIX "Swig Interface Files")
SET(NUPIC_INCLUDE_GROUP_PREFIX "Header Files")
SET(NUPIC_SOURCE_GROUP_PREFIX "Source Files")

# Globals
SET_PROPERTY(GLOBAL PROPERTY USE_FOLDERS ON)

# Project
project(Nupic.Core VERSION 0.1 LANGUAGES CXX)

# CapnProto

include(ExternalProject)

ExternalProject_Add(
  CapnProto

  GIT_REPOSITORY "https://github.com/capnproto/capnproto.git"
  GIT_TAG "v0.6.1"
   
  UPDATE_COMMAND ""
  PATCH_COMMAND ""
  
  SOURCE_DIR "${CMAKE_BINARY_DIR}/CapnProto"
  SOURCE_SUBDIR "c++"
  CMAKE_ARGS -DBuildShared=ON -DBuildExamples=OFF
    
  TEST_COMMAND ""
)

set(CapnProto_INCLUDE_DIRS "${CMAKE_BINARY_DIR}/CapnProto/c++/src")
set(CapnProto_LIBRARIES "${CMAKE_SHARED_LIBRARY_PREFIX}CapnProto${CMAKE_SHARED_LIBRARY_SUFFIX}")

include_directories(${CapnProto_INCLUDE_DIRS})

find_package(Boost REQUIRED)

# Nupic.Core

add_subdirectory(nupic.core)