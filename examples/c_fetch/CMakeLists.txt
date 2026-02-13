cmake_minimum_required(VERSION 3.14)
project(c_fetch C)

include(FetchContent)

FetchContent_Declare(
    cclib_c
    GIT_REPOSITORY https://github.com/pingponghero12/c-cpp-lib.git
    GIT_TAG main
    SOURCE_SUBDIR cclib_c
)

FetchContent_MakeAvailable(cclib_c)

add_executable(c_fetch main.c)

target_link_libraries(c_fetch PRIVATE cclib::c)
