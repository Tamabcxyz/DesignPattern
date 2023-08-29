cmake_minimum_required(VERSION 3.24.3)
set(
    abstractfactory_src
    src/Linux.cpp
    src/LinuxTemplate.cpp
    src/Window.cpp
    src/WindowTemplate.cpp
    )

include_directories(include)
add_library(abstractfactory STATIC ${abstractfactory_src})
target_include_directories(abstractfactory PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

