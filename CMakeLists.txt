cmake_minimum_required(VERSION 3.31)
project(GraphTool)

set(CMAKE_CXX_STANDARD 14)

include_directories(${PROJECT_SOURCE_DIR}/include)

file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")

add_executable(GraphTool ${SOURCES})
