//
// Created by TiagoF on 3/15/2024.
//

#ifndef PROJECT_1_DATAPARSER_H
#define PROJECT_1_DATAPARSER_H

#include <fstream>
#include <sstream>
#include <charconv>
#include <vector>
#include <algorithm>
#include "../GraphStructures/City.h"
#include "../GraphStructures/Pipe.h"
#include "../GraphStructures/Reservoir.h"
#include "../GraphStructures/Station.h"
#include "../GraphStructures/Contexts/Contexts.h"
#include "../GraphStructures/Graph.h"

namespace DataReader {
    int fetch_cities(const std::string& city_file_path, std::vector<CityContext>& city_info_container);
    int fetch_pipes(const std::string& pipe_file_path, std::vector<CityContext>& pipe_info_container);
    int fetch_reservoirs(const std::string& reservoir_file_path, std::vector<ReservoirContext>& reservoir_info_container);
    int fetch_stations(const std::string& station_file_path, std::vector<StationContext>& station_info_container);
    int fetch_data(const std::string& city_file_path, std::vector<CityContext>& city_info_container,
                   const std::string& pipe_file_path, std::vector<PipeContext>& pipe_info_container,
                   const std::string& reservoir_file_path, std::vector<ReservoirContext>& reservoir_info_container,
                   const std::string& station_file_path, std::vector<StationContext>& station_info_container);


    CityContext generateCityContext(unsigned int id, std::string code, std::string name, double demand, unsigned int population);

    void build_graph(Graph& graph,
                   const std::vector<CityContext>& city_info_container,
                   const std::vector<ReservoirContext>& reservoir_info_container,
                   const std::vector<StationContext>& station_info_container,
                   const std::vector<PipeContext>& pipe_info_container);
}

#endif //PROJECT_1_DATAPARSER_H
