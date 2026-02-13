cmake_minimum_required(VERSION 3.14)

add_library(cclib_cpp INTERFACE)
add_library(cclib::cpp ALIAS cclib_cpp)

target_include_directories(cclib_cpp INTERFACE 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)


target_compile_features(cclib_cpp INTERFACE cxx_std_20)

if(UNIX AND NOT APPLE)
    target_link_libraries(cclib_c INTERFACE rt)
endif()
