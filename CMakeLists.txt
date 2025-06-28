cmake_minimum_required(VERSION 3.30.5)
project(GraphTool)

set(CMAKE_CXX_STANDARD 14)

include_directories(${PROJECT_SOURCE_DIR}/include)

file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")

add_executable(GraphTool ${SOURCES}
        src/IGraph.cpp
        include/IGraph.h
        src/Edge.cpp
        include/Edge.h
        src/Vertex.cpp
        src/Graph_IO.cpp
        include/Graph_IO.h
        include/Vertex.h)
