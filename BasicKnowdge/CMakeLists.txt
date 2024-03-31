cmake_minimum_required(VERSION 3.24.3)
set(
    basicknowdge_src
    src/SingleResponsibilityPrinciple.cpp
    )

include_directories(include)
add_library(basicknowdge STATIC ${basicknowdge_src})
target_include_directories(basicknowdge PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)