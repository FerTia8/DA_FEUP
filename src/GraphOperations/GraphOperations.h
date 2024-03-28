//
// Created by TiagoF on 3/23/2024.
//

#ifndef PROJECT_1_GRAPHOPERATIONS_H
#define PROJECT_1_GRAPHOPERATIONS_H

#include "../GraphStructures/Graph.h"

namespace GraphOperations {
    template <typename SourceVertexType> std::vector<Vertex*> bfs(Graph& g, const std::string& code) {
        std::vector<Vertex*> res;

        SourceVertexType* src = g.findVertex<SourceVertexType>(code);
        if (!src) return res;

        g.markAllVerticesUnvisited();

        std::queue<Vertex*> q;
        q.push(src);
        src->setVisited(true);
        while (!q.empty()) {
            Vertex* v = q.front();
            q.pop();
            res.push_back(v);
            for (Pipe* p: v->getOutgoing()) {
                Vertex* dv = p->getDest();
                if (!dv->isVisited()) {
                    q.push(dv);
                    dv->setVisited(true);
                }
            }
        }
        return res;
    }

    void edmondsKarp(Graph& g);
    void edmondsKarp(Graph& g, const std::string& city_code);
}

#endif //PROJECT_1_GRAPHOPERATIONS_H