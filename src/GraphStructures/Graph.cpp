//
// Created by TiagoF on 3/17/2024.
//

#include "Graph.h"

std::vector<Vertex*> Graph::getVertexSet() const {
    return vertices;
}

template<> std::vector<City*> &Graph::getVerticesSubset() {
    return cities;
}
template<> std::vector<Reservoir*>& Graph::getVerticesSubset<Reservoir>() {
    return reservoirs;
}
template<> std::vector<Station*>& Graph::getVerticesSubset<Station>() {
    return stations;
}

std::unordered_set<Pipe*> Graph::getPipeSet() const {
    std::unordered_set<Pipe*> pipes;
    for (Vertex* v: vertices) {
        for (Pipe *p: v->getOutgoing()) {
            pipes.insert(p);
        }
    }
    return pipes;
}

void Graph::markAllVerticesUnvisited() {
    for (Vertex* v: vertices) {
        v->setVisited(false);
    }
}

void Graph::setAllPipesFlowZero() const {
    for (Pipe* p: getPipeSet()) {
        p->setFlow(0);
    }
}
