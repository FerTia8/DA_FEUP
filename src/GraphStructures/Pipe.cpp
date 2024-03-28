#include "Pipe.h"

Pipe::Pipe(Vertex* src, Vertex* dest, const PipeContext &context)
    : vertex1(src), vertex2(dest), direction(context.direction), capacity(context.capacity) {};

unsigned int Pipe::getCapacity() const {
    return capacity;
}

bool Pipe::isDirection() const {
    return direction;
}

Vertex *Pipe::getOrig() const {
    return vertex1;
}

Vertex* Pipe::getDest() const {
    return vertex2;
}

int Pipe::getFlow() const {
    return flow;
}

void Pipe::setFlow(int _flow) {
    flow = _flow;
}