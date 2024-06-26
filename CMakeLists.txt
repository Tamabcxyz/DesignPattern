cmake_minimum_required(VERSION 3.24.3)
project(DesignPattern VERSION 1.0)
set(CMAKE_C_COMPILER "/usr/bin/cc")
set(CMAKE_CXX_COMPILER "/usr/bin/c++")

option(ADAPTER_DP "Enable adapter lib" OFF)
option(FACTORYMETHOD_DP "Enable factorymethod lib" OFF)
option(ABSTRACTFACTORY_DP "Enable abstractfactory lib" OFF)
option(BUILDER_DP "Enable builder lib" OFF)
option(PROTOTYPE_DP "Enable prototype lib" OFF)
option(SINGLETON_DP "Enable singleton lib" OFF)
option(BASICKNOWDGE "Enable basic knowdge lib" ON)

if(ADAPTER_DP)
    # Include the Adapter directory
    add_subdirectory(Adapter)
    list(APPEND EXTRA_INCLUDES ${PROJECT_SOURCE_DIR}/Adapter/include)
    list(APPEND EXTRA_LIBS adapter)
endif()
if(FACTORYMETHOD_DP)
    add_subdirectory(FactoryMethod)
    list(APPEND EXTRA_INCLUDES ${PROJECT_SOURCE_DIR}/FactoryMethod/include)
    list(APPEND EXTRA_LIBS factorymethod)
endif()
if(ABSTRACTFACTORY_DP)
    add_subdirectory(AbstractFactory)
    list(APPEND EXTRA_INCLUDES ${PROJECT_SOURCE_DIR}/AbstractFactory/include)
    list(APPEND EXTRA_LIBS abstractfactory)
endif()
if(BUILDER_DP)
    add_subdirectory(Builder)
    list(APPEND EXTRA_INCLUDES ${PROJECT_SOURCE_DIR}/Builder/include)
    list(APPEND EXTRA_LIBS builder)
endif()
if(PROTOTYPE_DP)
    add_subdirectory(Prototype)
    list(APPEND EXTRA_INCLUDES ${PROJECT_SOURCE_DIR}/Prototype/include)
    list(APPEND EXTRA_LIBS prototype)
endif()
if(SINGLETON_DP)
    add_subdirectory(Singleton)
    list(APPEND EXTRA_INCLUDES ${PROJECT_SOURCE_DIR}/Singleton/include)
    list(APPEND EXTRA_LIBS singleton)
endif()
if(BASICKNOWDGE)
    add_subdirectory(BasicKnowdge)
    list(APPEND EXTRA_INCLUDES ${PROJECT_SOURCE_DIR}/BasicKnowdge/include)
    list(APPEND EXTRA_LIBS basicknowdge)
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


