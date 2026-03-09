cmake_minimum_required(VERSION 3.14)
project(cpp_sort_tests)

include(FetchContent)

FetchContent_Declare(
    cclib_cpp
    GIT_REPOSITORY https://github.com/pingponghero12/c-cpp-lib.git
    GIT_TAG main
    SOURCE_SUBDIR cclib_cpp
)

FetchContent_MakeAvailable(cclib_cpp)

add_executable(cpp_sort_tests main.cpp)

target_link_libraries(cpp_sort_tests PRIVATE cclib::cpp)
