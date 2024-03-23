#include "Pipe.h"

Pipe::Pipe(Vertex* src, Vertex* dest, const PipeContext &context)
    : vertex1(src), vertex2(dest), direction(context.direction), capacity(context.capacity) {};

unsigned int Pipe::getCapacity() const {
    return capacity;
}

bool Pipe::isDirection() const {
    return direction;
}

// since dealing with undirected graphs, pass initial vertex so that getDest() returns the second one
Vertex* Pipe::getDest(Vertex* init_v) const {
    return (vertex1 == init_v) ? vertex2 : vertex1;
}
