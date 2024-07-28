# CMake minimum version
cmake_minimum_required(VERSION 3.10)

# Project name and version
project(Raytracer VERSION 1.0)

# Set C++ standard
# set(CMAKE_CXX_STANDARD 11)
# set(CMAKE_CXX_STANDARD_REQUIRED True)

# Specify the source files
set(SOURCES
    # header files

    # source files
    main.cpp
)

# Add executable target
add_executable(Raytracer ${SOURCES})

# Include directories
target_include_directories(Raytracer PRIVATE ${PROJECT_SOURCE_DIR})
