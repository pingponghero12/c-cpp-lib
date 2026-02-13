cmake_minimum_required(VERSION 3.14)
project(c_build LANGUAGES C)

add_executable(c_build c_build.c)

target_link_libraries(c_build PRIVATE cclib::c)
get_target_property(INCLUDES cclib_c INTERFACE_INCLUDE_DIRECTORIES)
message(STATUS "cclib_c includes: ${INCLUDES}")
