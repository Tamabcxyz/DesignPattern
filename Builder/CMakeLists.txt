cmake_minimum_required(VERSION 3.24.3)
set(
    builder_src
    src/Pizza.cpp
    src/PepperoniPizza.cpp
    src/SausagePizza.cpp
    src/Shipper.cpp
    )

include_directories(include)
add_library(builder STATIC ${builder_src})
target_include_directories(builder PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

