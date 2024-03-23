#ifndef PROJECT_1_VERTEX_H
#define PROJECT_1_VERTEX_H

#include <vector>
#include <utility>
#include <string>
#include <iostream>
#include "Pipe.h"
#include "Contexts/Contexts.h"

class Pipe;

class Vertex {
public:
    Vertex(unsigned int id, std::string code);
    virtual ~Vertex() = default;

    unsigned int getId() const;
    const std::string& getCode() const;
    bool isVisited() const;
    bool isProcessing() const;

    template<typename ContextType, typename VertexType> Pipe *addPipe(VertexType *d, const PipeContext &context) {
        auto newPipe = new Pipe(this, d, context);
        adj.push_back(newPipe);
        d->adj.push_back(newPipe);
        return newPipe;
    }

    std::vector<Pipe *> getAdj() const;

protected:
    unsigned int id;
    std::string code;

    std::vector<Pipe*> adj;

    // aux
    bool visited = false;
    bool processing = false;
};


#endif //PROJECT_1_VERTEX_H
