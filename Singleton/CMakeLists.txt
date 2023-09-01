cmake_minimum_required(VERSION 3.24.3)
set(
    singleton_src
    src/WeakSingleton.cpp
    src/StrongSingleton.cpp
)
include_directories(include)
add_library(singleton STATIC ${singleton_src})
target_include_directories(singleton PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)