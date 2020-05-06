#######################################################################
# Find all necessary and optional CAUDIO dependencies
#######################################################################

# CAUDIO_DEPENDENCIES_DIR can be used to specify a single base
# folder where the required dependencies may be found.
set(CAUDIO_DEPENDENCIES_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Dependencies")

include(FindPkgMacros)
getenv_path(CAUDIO_DEPENDENCIES_DIR)
message(STATUS "Search path: ${CAUDIO_DEPENDENCIES_DIR}")

# give guesses as hints to the find_package calls
set(CMAKE_PREFIX_PATH ${CAUDIO_DEPENDENCIES_DIR} ${CMAKE_PREFIX_PATH})
set(CMAKE_FRAMEWORK_PATH ${CAUDIO_DEPENDENCIES_DIR} ${CMAKE_FRAMEWORK_PATH})

#######################################################################
# Core dependencies
#######################################################################

# Find OpenAL

add_library(openal32 STATIC IMPORTED)
set_property(TARGET openal32 PROPERTY IMPORTED_LOCATION ${CAUDIO_DEPENDENCIES_DIR}/lib/Debug/OpenAL32.lib)

# Add library and include paths from the dependencies
include_directories(
  ${CAUDIO_DEPENDENCIES_DIR}/include
)
