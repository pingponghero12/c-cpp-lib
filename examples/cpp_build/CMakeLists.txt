cmake_minimum_required(VERSION 3.14)
project(cpp_build LANGUAGES CXX)

add_executable(cpp_build main.cpp)

target_link_libraries(cpp_build PRIVATE cclib::cpp)
get_target_property(INCLUDES cclib_cpp INTERFACE_INCLUDE_DIRECTORIES)
message(STATUS "cclib_cpp includes: ${INCLUDES}")
