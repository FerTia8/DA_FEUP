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

Pipe *Vertex::getPath() const {
    return path;
}

std::vector<Pipe *> Vertex::getOutgoing() const {
    return outgoing;
}

std::vector<Pipe *> Vertex::getIncoming() const {
    return incoming;
}

void Vertex::setVisited(bool _visited) {
    visited = _visited;
}

void Vertex::setProcessing(bool _processing) {
    processing = _processing;
}

void Vertex::setPath(Pipe *_path) {
    path = _path;
}