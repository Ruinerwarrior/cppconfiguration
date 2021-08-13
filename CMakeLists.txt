# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.18.1)

set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake
  CACHE STRING "Vcpkg toolchain file")

project ("cppconfiguration")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(CTest)
enable_testing()

option(BUILD_STATIC_LIB "Build the static library" OFF)
option(BUILD_TESTS "Build test programs" TRUE)
option(BUILD_EXAMPLE "Build example programs" OFF)

# Find vcpkg packages
find_package(nlohmann_json CONFIG REQUIRED)
find_package(Catch2 REQUIRED Config)

# Include sub-projects.
add_subdirectory ("cppconfiguration")

if(BUILD_EXAMPLE)
	add_subdirectory ("example")
endif(BUILD_EXAMPLE)

if(BUILD_TESTS)
	add_subdirectory ("tests")
endif(BUILD_TESTS)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
