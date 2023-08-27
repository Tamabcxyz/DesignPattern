cmake_minimum_required(VERSION 3.24.3)
project(DesignPattern VERSION 1.0)
set(CMAKE_C_COMPILER "/usr/bin/cc")
set(CMAKE_CXX_COMPILER "/usr/bin/c++")


# Add the main executable
add_executable(main main.cpp)

# # Include the Adapter directory
# add_subdirectory(Adapter)

# target_link_directories(main PRIVATE ${CMAKE_SOURCE_DIR}/Adapter)
# target_link_libraries(main adder)


