cmake_minimum_required(VERSION 3.24.3)
project(DesignPattern VERSION 1.0)
set(CMAKE_C_COMPILER "/usr/bin/cc")
set(CMAKE_CXX_COMPILER "/usr/bin/c++")

option(ADAPTER_DP "Enable adapter lib" ON)

if(ADAPTER_DP)
    # Include the Adapter directory
    add_subdirectory(Adapter)
    list(APPEND EXTRA_INCLUDES ${PROJECT_SOURCE_DIR}/Adapter/include)
    list(APPEND EXTRA_LIBS adapter)
endif()

# Add the main executable
add_executable(main main.cpp)

# Add submodule include folder
target_include_directories(
    main 
    PUBLIC
    ${CMAKE_BINARY_DIR} # For config.h
    ${EXTRA_INCLUDES} # For include folder
)

# # Point out where lib exist in target/build (In this case target/build/Adapter/libadapter.a)
# target_link_directories(main PRIVATE ${CMAKE_SOURCE_DIR}/Adapter)

target_link_libraries(main PRIVATE ${EXTRA_LIBS})

configure_file(config.h.in config.h)


