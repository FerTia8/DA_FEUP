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
    Pipe *getPath() const;

    void setVisited(bool _visited);
    void setProcessing(bool _processing);
    void setPath(Pipe* _path);

    template<typename VertexType> Pipe *addPipe(VertexType *d, const PipeContext &context) {
        auto newPipe = new Pipe(this, d, context);
        outgoing.push_back(newPipe);
        d->incoming.push_back(newPipe);
        return newPipe;
    }

    std::vector<Pipe *> getOutgoing() const;
    std::vector<Pipe *> getIncoming() const;

protected:
    unsigned int id;
    std::string code;

    std::vector<Pipe*> outgoing;
    std::vector<Pipe*> incoming;

    // aux
    bool visited = false;
    bool processing = false;
    Pipe* path = nullptr;
};


#endif //PROJECT_1_VERTEX_H
