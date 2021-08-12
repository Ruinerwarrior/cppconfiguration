# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.18.1)

set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake
  CACHE STRING "Vcpkg toolchain file")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project ("cppconfiguration")

option(BUILD_STATIC_LIB "Build the static library" ON)
option(BUILD_TESTS "Build test programs" OFF)
option(BUILD_EXAMPLE "Build test programs" ON)

# Find vcpkg packages
find_package(nlohmann_json CONFIG REQUIRED)

# Include sub-projects.
add_subdirectory ("cppconfiguration")

if(BUILD_EXAMPLE)
	add_subdirectory ("example")
endif(BUILD_EXAMPLE)