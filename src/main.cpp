#include <iostream>
#include <vector>
#include "DataParser.h"
#include "GraphStructures/Graph.h"

int main() {
    std::vector<CityContext> city_info; std::vector<ReservoirContext> reservoir_info; std::vector<StationContext> station_info;
    std::vector<PipeContext> pipe_info;
    std::cout << DataReader::fetch_data("../Project1DataSetSmall/Cities_Madeira.csv", city_info,
                                        "../Project1DataSetSmall/Pipes_Madeira.csv", pipe_info,
                                        "../Project1DataSetSmall/Reservoirs_Madeira.csv", reservoir_info,
                                        "../Project1DataSetSmall/Stations_Madeira.csv", station_info) << std::endl;

    Graph main_graph;
    /*
    std::cout << main_graph.addVertex<CityContext, City>(city_info[0]);
    std::cout << main_graph.addVertex<ReservoirContext, Reservoir>(reservoir_info[1]);
    std::cout << main_graph.addVertex<StationContext, Station>(station_info[0]);
    std::cout << main_graph.addVertex<StationContext, Station>(station_info[0]);
    std::cout << '\n' << main_graph.findVertex<StationContext, Station>(station_info[0]);
    */
    DataReader::build_graph(main_graph, city_info, reservoir_info, station_info, pipe_info);
    auto x = main_graph.findVertex<StationContext, Station>("PS_2");
    for (auto v: x->getAdj()) {
        std::cout << v->getDest(x)->getCode() << '\n';
        // for example, let's say I want to retrieve the city connected to v and get its info
        City* c = main_graph.findVertex<CityContext, City>(v->getDest(x)->getCode());
        if (c) {
            std::cout << "Found the City: " << c->getName();
            break;
        }
    }

    return 0;
}