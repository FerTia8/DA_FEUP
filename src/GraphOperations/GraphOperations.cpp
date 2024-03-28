//
// Created by TiagoF on 3/23/2024.
//

#include "GraphOperations.h"

namespace {
    // ***** EDMONDS-KARP ALGORITHM ***** //
    void testAndVisit(std::queue<Vertex*>& q, Pipe* p, Vertex* w, int residual) {
        if (!w->isVisited() && residual > 0) {
            w->setVisited(true);
            w->setPath(p);
            q.push(w);
        }
    }

    bool findAugmentingPath(Graph& g, Reservoir* src, City* sink) {
        g.markAllVerticesUnvisited();

        std::queue<Vertex*> q;
        q.push(src);
        src->setVisited(true);

        while (!q.empty() && !sink->isVisited()) {
            Vertex* v = q.front();
            q.pop();
            for (Pipe* p: v->getOutgoing()) {
                std::cout << "Out:" << p->getOrig()->getCode() << '-' << p->getDest()->getCode() << ' ' << (p->getCapacity() - p->getFlow()) << '\n';
                testAndVisit(q, p, p->getDest(), p->getCapacity() - p->getFlow());
            }
            for (Pipe* p: v->getIncoming()) {
                std::cout << "In:" << p->getOrig()->getCode() << '-' << p->getDest()->getCode() << ' ' << p->getFlow() << '\n';
                testAndVisit(q, p, p->getOrig(), p->getFlow());
            }
        }

        return sink->isVisited();
    }

    int findMinResidualAlongPath(Reservoir* src, City* trg) {
        int f = INT_MAX;

        for (Vertex* v = trg; v != src; ) {
            Pipe* p = v->getPath();
            if (p->getDest() == v) {
                f = std::min(f, (int) p->getCapacity() - p->getFlow());
                v = p->getOrig();
            } else {
                f = std::min(f, p->getFlow());
                v = p->getDest();
            }
        }

        return f;
    }

    void augmentFlowAlongPath(Vertex* src, Vertex* trg, int f) {
        std::cout << src->getCode() << "$" << '\n';
        for (auto v = trg; v != src; ) {
            Pipe* p = v->getPath();
            int flow = p->getFlow();
            if (p->getDest() == v) {
                p->setFlow(flow + f);
                v = p->getOrig();
            } else {
                p->setFlow(flow - f);
                v = p->getDest();
            }
        }
    }
}

namespace GraphOperations {
    void edmondsKarp(Graph &g) {
        g.setAllPipesFlowZero();
        std::vector<City*> targets = g.getVerticesSubset<City>();
        std::vector<Reservoir*> sources = g.getVerticesSubset<Reservoir>();

        // TODO: set reservoir delivery limit, looping through reservoirs has no effect so far
        for (Reservoir* reservoirSource: sources) {
            for (City *cityTarget: targets) {
                while (findAugmentingPath(g, reservoirSource, cityTarget)) {
                    int f = findMinResidualAlongPath(reservoirSource, cityTarget);
                    augmentFlowAlongPath(reservoirSource, cityTarget, f);
                }
            }
        }
    }

    void edmondsKarp(Graph &g, const std::string &city_code) {
        City* citySink = g.findVertex<City>(city_code);
        // if (!citySink) return -1;

        g.setAllPipesFlowZero();
        std::vector<Reservoir*> sources = g.getVerticesSubset<Reservoir>();

        // TODO: set reservoir delivery limit, looping through reservoirs has no effect so far
        for (Reservoir* reservoirSource: sources) {
            while (findAugmentingPath(g, reservoirSource, citySink)) {
                int f = findMinResidualAlongPath(reservoirSource, citySink);
                augmentFlowAlongPath(reservoirSource, citySink, f);
            }
        }
    }
}