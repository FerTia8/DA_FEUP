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

    Vertex* getDest(Vertex* init_v) const;
private:
    Vertex* vertex1;
    Vertex* vertex2;

    unsigned int capacity;
    bool direction;
};

#endif //PROJECT_1_PIPE_H