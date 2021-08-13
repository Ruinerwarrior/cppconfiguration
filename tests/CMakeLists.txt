cmake_minimum_required (VERSION 3.18.1)

add_executable(configuration_builder.tests "src/main.cpp" "src/configuration_builder.tests.cpp")
target_link_libraries(configuration_builder.tests PRIVATE cppconfiguration)
target_link_libraries(configuration_builder.tests PRIVATE Catch2::Catch2)
add_test(name configuration_builder.tests COMMAND configuration_builder.tests)

configure_file("${CMAKE_CURRENT_LIST_DIR}/appsettings.json" "${CMAKE_CURRENT_BINARY_DIR}/appsettings.json")
configure_file("${CMAKE_CURRENT_LIST_DIR}/appsettings_empty.json" "${CMAKE_CURRENT_BINARY_DIR}/appsettings_empty.json")