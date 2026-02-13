cmake_minimum_required(VERSION 3.14)
project(c-cpp-lib VERSION 0.0.1 LANGUAGES C CXX)

add_subdirectory(cclib_c)
#add_subdirectory(cclib_cpp)

if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
    option(BUILD_EXAMPLES "Build examples" ON)

    if (BUILD_EXAMPLES) 
        add_subdirectory(examples)
    endif()
endif()
