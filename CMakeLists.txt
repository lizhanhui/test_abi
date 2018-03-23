cmake_minimum_required(VERSION 2.8)

project(test_abi)

if (POLICY CMP0042)
    cmake_policy(SET CMP0042 NEW)
endif ()

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_VERBOSE_MAKEFILE ON)

add_library(animal SHARED animal.cpp)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} dl)

set_target_properties(${PROJECT_NAME} PROPERTIES
    LINK_FLAGS "-Wl,-rpath,\$ORIGIN")

# target_link_libraries(${PROJECT_NAME} animal)
