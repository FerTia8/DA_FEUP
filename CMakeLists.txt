cmake_minimum_required(VERSION 3.26)
project(WaterSupplyManagement)

set(CMAKE_CXX_STANDARD 14)

include_directories(src/DataParser)

add_executable(WaterSupplyManagement
        src/DataParser/DataParser.cpp
        src/DataParser/DataParser.h
        src/main.cpp
        src/GraphStructures/Graph.cpp
        src/GraphStructures/Graph.h
        src/GraphStructures/Pipe.cpp
        src/GraphStructures/Pipe.h
        src/GraphStructures/City.cpp
        src/GraphStructures/City.h
        src/GraphStructures/Reservoir.cpp
        src/GraphStructures/Reservoir.h
        src/GraphStructures/Station.cpp
        src/GraphStructures/Station.h
        src/GraphStructures/Vertex.cpp
        src/GraphStructures/Vertex.h
        src/GraphStructures/Pipe.h
        src/GraphStructures/Contexts/Contexts.cpp
        src/GraphStructures/Contexts/Contexts.h
        src/GraphOperations/GraphOperations.h
        src/GraphOperations/GraphOperations.cpp
)
