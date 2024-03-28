//
// Created by TiagoF on 3/17/2024.
//

#ifndef PROJECT_1_PIPE_H
#define PROJECT_1_PIPE_H

#include <string>
#include <utility>
#include "Vertex.h"
#include "Contexts/Contexts.h"

class Vertex;

class Pipe {
public:
    Pipe(Vertex* src, Vertex* dest, const PipeContext& context);

    unsigned int getCapacity() const;
    bool isDirection() const;

    Vertex* getDest() const;
    Vertex* getOrig() const;

    int getFlow() const;
    void setFlow(int flow);

private:
    Vertex* vertex1;
    Vertex* vertex2;
    unsigned int capacity;
    bool direction;

    // aux
    int flow;
};

#endif //PROJECT_1_PIPE_H