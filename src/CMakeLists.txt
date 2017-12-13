cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

# Targets
# TODO Preferences based on generator? ...Overkill?
set(NUPIC_BINDINGS_GROUP_PREFIX "Swig Interface Files")
set(NUPIC_INCLUDE_GROUP_PREFIX "Header Files")
set(NUPIC_SOURCE_GROUP_PREFIX "Source Files")

# Globals
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "CMake Predefined Targets")

# Project
project(Nupic.Core VERSION 0.1 LANGUAGES CXX)

# Core
add_subdirectory(nupic.core)