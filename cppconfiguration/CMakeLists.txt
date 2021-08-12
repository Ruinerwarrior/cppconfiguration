# CMakeList.txt : CMake project for cppconfiguration, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.18.1)

# Add source to this project's executable.
set(LIB_SOURCES 
	"src/configuration_builder.cpp"
	"src/configuration_root.cpp"
	"src/configuration_section.cpp"
)

if(BUILD_STATIC_LIB) 
	add_library (cppconfiguration STATIC ${LIB_SOURCES})
else()
	add_library (cppconfiguration SHARED ${LIB_SOURCES})
endif(BUILD_STATIC_LIB)

target_include_directories(cppconfiguration PUBLIC "include")

# TODO: Add tests and install targets if needed.
target_link_libraries(cppconfiguration PUBLIC nlohmann_json nlohmann_json::nlohmann_json)