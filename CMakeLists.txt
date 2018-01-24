cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(nupic VERSION 0.1 LANGUAGES CXX)

# Preferences
set(NUPIC_HEADER_GROUP_PREFIX "Header Files")
set(NUPIC_SOURCE_GROUP_PREFIX "Source Files")

# Global Settings
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "CMake Predefined Targets")

# Files
file(GLOB_RECURSE HEADERS "./inc/*" "./inc/**/*")
file(GLOB_RECURSE SOURCES "./src/*" "./src/**/*")

# Library
add_library(nupic ${HEADERS} ${SOURCES})

include_directories(inc)

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}/inc" PREFIX ${NUPIC_HEADER_GROUP_PREFIX} FILES ${HEADERS})
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}/src" PREFIX ${NUPIC_SOURCE_GROUP_PREFIX} FILES ${SOURCES})

# Boost
find_package(Boost REQUIRED)
target_link_libraries(nupic PRIVATE ${Boost_LIBRARIES})
target_include_directories(nupic PRIVATE ${Boost_INCLUDE_DIRS})

# Yaml
find_package(yaml-cpp REQUIRED)
target_link_libraries(nupic PRIVATE yaml-cpp)

# ZLib
find_package(ZLib REQUIRED)
target_link_libraries(nupic PRIVATE ${ZLib_LIBRARIES})
target_include_directories(nupic PRIVATE ${ZLib_INCLUDE_DIRS})
