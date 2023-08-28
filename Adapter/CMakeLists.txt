cmake_minimum_required(VERSION 3.24.3)
set(
    adapter_src
    src/Target.cpp
    )
# add to include it in cpp file src/Target.cpp
include_directories(include)
add_library(adapter STATIC ${adapter_src})
# add header file attached into lib adapter
target_include_directories(adapter PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

