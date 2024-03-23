//
// Created by TiagoF on 3/17/2024.
//

#include "Graph.h"

std::vector<Vertex*> Graph::getVertexSet() const {
    return vertices;
}

template<> std::vector<City*>& Graph::getVerticesSubset<City>() {
    return cities;
}
template<> std::vector<Reservoir*>& Graph::getVerticesSubset<Reservoir>() {
    return reservoirs;
}
template<> std::vector<Station*>& Graph::getVerticesSubset<Station>() {
    return stations;
}