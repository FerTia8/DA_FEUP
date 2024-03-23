//
// Created by TiagoF on 3/19/2024.
//

#ifndef PROJECT_1_CONTEXTS_H
#define PROJECT_1_CONTEXTS_H

#include <string>

struct VertexContext {
    virtual ~VertexContext() = default;
    unsigned int id;
    std::string code;
};

struct CityContext : public VertexContext {
    std::string name;
    double demand;
    unsigned int population;
};

struct ReservoirContext : public VertexContext {
    std::string reservoir;
    std::string municipality;
    unsigned int max_delivery; // m3/sec
};

struct StationContext : public VertexContext {};

struct PipeContext {
    std::string service_point_A;
    std::string service_point_B;
    unsigned int capacity;
    bool direction;
};


#endif //PROJECT_1_CONTEXTS_H
