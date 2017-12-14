cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(Nupic.Core VERSION 0.1 LANGUAGES CXX)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}")

set(CMAKE_VERBOSE_MAKEFILE OFF)

get_filename_component(REPOSITORY_DIR ${PROJECT_SOURCE_DIR} ABSOLUTE)

if(POLICY CMP0046)
  cmake_policy(VERSION 3.3)
  # The new policy for add_dependencies is to now error if a dependency target
  # is not found. The old policy didn't care and continued through configuration
  cmake_policy(SET CMP0046 OLD)
endif()

if(POLICY CMP0054)
  # The OLD behavior for this policy is to dereference variables and interpret
  # keywords even if they are quoted or bracketed. The NEW behavior is to not
  # dereference variables or interpret keywords that have been quoted or bracketed.
  cmake_policy(SET CMP0054 OLD)
endif()

message(STATUS "CMAKE_CXX_COMPILER_ID = ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "CMAKE_C_COMPILER      = ${CMAKE_C_COMPILER}")
message(STATUS "CMAKE_CXX_COMPILER    = ${CMAKE_CXX_COMPILER}")
message(STATUS "CMAKE_BUILD_TYPE      = ${CMAKE_BUILD_TYPE}")
message(STATUS "CMAKE_INSTALL_PREFIX  = ${CMAKE_INSTALL_PREFIX}")


# Identify platform name.
string(TOLOWER ${CMAKE_SYSTEM_NAME} PLATFORM)

# Define a platform suffix, eg ${PLATFORM}${BITNESS}${PLATFORM_SUFFIX}
if (MSYS OR MINGW)
  set(PLATFORM_SUFFIX -gcc)
endif()


# Make sure we can link against any specified paths.
include_directories(SYSTEM ${CMAKE_INCLUDE_PATH})

set(EP_BASE ${CMAKE_BINARY_DIR}/ThirdParty)

# Determine common toolchain settings, compiler and link flags
include(CommonCompilerConfig)

#################
#				#
#   NEW STUFF	#
#				#
#################

# Targets
# TODO Preferences based on generator? ...Overkill?
set(NUPIC_BINDINGS_GROUP_PREFIX "Swig Interface Files")
set(NUPIC_HEADER_GROUP_PREFIX "Header Files")
set(NUPIC_SOURCE_GROUP_PREFIX "Source Files")

# Globals
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "CMake Predefined Targets")

# Core
add_subdirectory(src)