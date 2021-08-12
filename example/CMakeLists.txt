# CMakeList.txt : CMake project for cppconfiguration, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.18.1)

# Add source to this project's executable.
add_executable (cppconfiguration_example "main.cpp")

# TODO: Add tests and install targets if needed.
target_link_libraries(cppconfiguration_example PRIVATE cppconfiguration)

configure_file("${CMAKE_CURRENT_LIST_DIR}/appsettings.json" "${CMAKE_CURRENT_BINARY_DIR}/appsettings.json")