#
# Compiler definitions specific to nupic.core code
#

# EXTRACT THIS

string(TOUPPER ${PLATFORM} platform_uppercase)

set(src_compiler_definitions
    ${COMMON_COMPILER_DEFINITIONS}
    ${CAPNP_COMPILER_DEFINITIONS}
    -DNTA_OS_${platform_uppercase}
    -DNTA_ARCH_${BITNESS}
    -DHAVE_CONFIG_H
    -DNTA_INTERNAL
    -DBOOST_MATH_NO_LONG_DOUBLE_MATH_FUNCTIONS
    -DBOOST_NO_WREGEX
    -DNUPIC2
    -DAPR_DECLARE_STATIC
    -DAPU_DECLARE_STATIC)

if(NOT "${CMAKE_SYSTEM_PROCESSOR}" STREQUAL "armv7l")
  set(src_compiler_definitions
      ${src_compiler_definitions}
      -DNTA_ASM)
endif()

if(NOT "${CMAKE_BUILD_TYPE}" STREQUAL "Release")
  set(src_compiler_definitions
      ${src_compiler_definitions}
      -DNTA_ASSERTIONS_ON)
endif()

if(${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU")
  set(src_compiler_definitions
      ${src_compiler_definitions}
      -DNTA_COMPILER_GNU)
elseif(${CMAKE_CXX_COMPILER_ID} MATCHES "Clang")
  set(src_compiler_definitions
      ${src_compiler_definitions}
      -DNTA_COMPILER_CLANG)
elseif(${CMAKE_CXX_COMPILER_ID} STREQUAL "MSVC")
  set(src_compiler_definitions
      ${src_compiler_definitions}
      -DNTA_COMPILER_MSVC)
elseif(${CMAKE_CXX_COMPILER_ID} STREQUAL "MinGW")
  set(src_compiler_definitions
      ${src_compiler_definitions}
      -DNTA_COMPILER_GNU
      -D_hypot=hypot)
endif()

add_definitions(${src_compiler_definitions})

#################
#				#
#   NEW STUFF	#
#				#
#################

# Files
file(GLOB_RECURSE BINDINGS "./bindings/**/*.i")
file(GLOB_RECURSE HEADERS "./include/**/*.*")
file(GLOB_RECURSE SOURCES "./src/**/*")

# Library
add_library(Nupic.Core ${BINDINGS} ${HEADERS} ${SOURCES})

include_directories(include)

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}/bindings" PREFIX ${NUPIC_BINDINGS_GROUP_PREFIX} FILES ${BINDINGS})
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}/include" PREFIX ${NUPIC_HEADER_GROUP_PREFIX} FILES ${HEADERS})
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}/src" PREFIX ${NUPIC_SOURCE_GROUP_PREFIX} FILES ${SOURCES})

# Boost
find_package(Boost REQUIRED)
target_link_libraries(Nupic.Core PRIVATE ${Boost_LIBRARIES})
target_include_directories(Nupic.Core PRIVATE ${Boost_INCLUDE_DIRS})

# CapnProto
find_package(CapnProto REQUIRED)
include_directories(${CAPNP_INCLUDE_DIRS})
add_definitions(${CAPNP_DEFINITIONS})

# Yaml
find_package(yaml-cpp REQUIRED)
target_link_libraries(Nupic.Core PRIVATE yaml-cpp)

# ZLib
find_package(ZLib REQUIRED)
target_link_libraries(Nupic.Core PRIVATE ${ZLib_LIBRARIES})
target_include_directories(Nupic.Core PRIVATE ${ZLib_INCLUDE_DIRS})

# APR
find_library(Apr REQUIRED)
target_link_libraries(Nupic.Core PRIVATE Apr)

# APR Util
find_library(AprUtil REQUIRED)
target_link_libraries(Nupic.Core PRIVATE AprUtil)