cmake_minimum_required(VERSION 3.24.3)
set(
    prototype_src
    src/Circle.cpp
    src/Square.cpp
    src/ShapeCache.cpp
)
include_directories(include)
add_library(prototype STATIC ${prototype_src})
target_include_directories(prototype PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)