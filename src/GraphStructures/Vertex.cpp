#include "Vertex.h"

// Getters
Vertex::Vertex(unsigned int id, std::string code) : id(id), code(std::move(code)) {};

unsigned int Vertex::getId() const {
    return id;
}

const std::string &Vertex::getCode() const {
    return code;
}

bool Vertex::isVisited() const {
    return visited;
}

bool Vertex::isProcessing() const {
    return processing;
}

std::vector<Pipe *> Vertex::getAdj() const {
    return adj;
}
