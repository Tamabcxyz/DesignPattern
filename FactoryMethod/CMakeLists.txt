cmake_minimum_required(VERSION 3.24.3)
set(
    factorymethod_src
    src/Iphone14.cpp
    src/Iphone15.cpp
    src/Factory.cpp
    src/App.cpp
)
include_directories(include)
add_library(factorymethod STATIC ${factorymethod_src})
target_include_directories(factorymethod PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)