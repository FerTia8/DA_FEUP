//
// Created by TiagoF on 3/17/2024.
//

#ifndef PROJECT_1_STATION_H
#define PROJECT_1_STATION_H

#include <string>
#include <utility>
#include "Vertex.h"
#include "Contexts/Contexts.h"

class Station: public Vertex {
public:
    explicit Station(const StationContext& context);
    Station(unsigned int id, std::string code);
private:
};


#endif //PROJECT_1_STATION_H
