cmake_minimum_required(VERSION 3.14)

add_library(cclib_c INTERFACE)
add_library(cclib::c ALIAS cclib_c)

target_include_directories(cclib_c INTERFACE 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)


target_compile_features(cclib_c INTERFACE c_std_99)

if(UNIX AND NOT APPLE)
    target_link_libraries(cclib_c INTERFACE rt)
endif()
