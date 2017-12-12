# Files
file(GLOB_RECURSE BINDINGS "./bindings/**/*.i")
file(GLOB_RECURSE INCLUDES "./include/**/*.*")
file(GLOB_RECURSE SOURCES "./src/**/*")

# Library
add_library(Nupic.Core ${BINDINGS} ${INCLUDES} ${SOURCES})

include_directories(include)

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}/bindings" PREFIX ${NUPIC_BINDINGS_GROUP_PREFIX} FILES ${BINDINGS})
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}/include" PREFIX ${NUPIC_INCLUDE_GROUP_PREFIX} FILES ${INCLUDES})
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}/src" PREFIX ${NUPIC_SOURCE_GROUP_PREFIX} FILES ${SOURCES})