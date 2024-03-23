// ADAPTED FROM GRAPH.H SUPPLIED IN CLASS

#ifndef PROJECT_1_GRAPH_H
#define PROJECT_1_GRAPH_H

#include <vector>
#include <algorithm>
#include "City.h"
#include "Reservoir.h"
#include "Station.h"

class Graph {
public:
    template<typename ContextType, typename VertexType> bool addVertex(const ContextType& context) {
        if (findVertex<ContextType, VertexType>(context)) return false;

        auto* new_vertex = new VertexType(context);
        getVerticesSubset<VertexType>().push_back(new_vertex);
        vertices.push_back(new_vertex);
        return true;
    }

    template<typename ContextType, typename VertexType> VertexType* findVertex(const ContextType& context) {
        std::vector<VertexType*>& subset = getVerticesSubset<VertexType>();
        auto it = std::find_if(subset.begin(), subset.end(), [context](Vertex* vA) {
            return (vA->getId() == context.id || vA->getCode() == context.code);
        });
        if (it == subset.end()) return nullptr;
        return *it;
    }

    template<typename ContextType, typename VertexType> VertexType* findVertex(const std::string& code) {
        std::vector<VertexType*>& subset = getVerticesSubset<VertexType>();
        auto it = std::find_if(subset.begin(), subset.end(), [code](Vertex* vA) {
            return (vA->getCode() == code);
        });
        if (it == subset.end()) return nullptr;
        return *it;
    }

    template<typename ContextType1, typename VertexType1, typename ContextType2, typename VertexType2>
    bool addPipe(const ContextType1& src, const ContextType2& dest, const PipeContext& pipeContext) {
        auto v1 = findVertex<ContextType1, VertexType1>(src);
        auto v2 = findVertex<ContextType2, VertexType2>(dest);

        if (!v1 || !v2)
            return false;

        v1->addPipe(v2, pipeContext);
    }

    template<typename ContextType1, typename VertexType1, typename ContextType2, typename VertexType2>
    bool addPipe(const std::string& src_code, const std::string& dest_code, const PipeContext& pipeContext) {
        auto v1 = findVertex<ContextType1, VertexType1>(src_code);
        auto v2 = findVertex<ContextType2, VertexType2>(dest_code);

        if (!v1 || !v2)
            return false;

        v1->template addPipe<ContextType2, VertexType2>(v2, pipeContext);
        return true;
    }

    std::vector<Vertex*> getVertexSet() const;
    template<typename VertexType> std::vector<VertexType*>& getVerticesSubset();

private:
    std::vector<Vertex*> vertices;
    std::vector<City*> cities;
    std::vector<Reservoir*> reservoirs;
    std::vector<Station*> stations;
};


#endif //PROJECT_1_GRAPH_H
