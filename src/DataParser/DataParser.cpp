#include "DataParser.h"

namespace DataReader {
    int fetch_cities(const std::string& city_file_path, std::vector<CityContext>& city_info_container) {
        std::ifstream in_cities(city_file_path);
        if (!in_cities.is_open())
            return 1;

        std::string line;
        std::string field;
        std::getline(in_cities, line);
        while (std::getline(in_cities, line)) {
            std::istringstream iss(line);
            CityContext cityContext;

            std::getline(iss, cityContext.name, ',');
            std::getline(iss, field, ',');
            std::from_chars(field.data(), field.data() + field.size(), cityContext.id);
            std::getline(iss, cityContext.code, ',');
            std::getline(iss, field, ',');
            std::from_chars(field.data(), field.data() + field.size(), cityContext.demand);
            std::getline(iss, field, ',');
            std::from_chars(field.data(), field.data() + field.size(), cityContext.population);

            city_info_container.push_back(cityContext);
        }

        return 0;
    }

    int fetch_pipes(const std::string& pipe_file_path, std::vector<PipeContext>& pipe_info_container) {
        std::ifstream in_pipes(pipe_file_path);
        if (!in_pipes.is_open())
            return 1;

        std::string line;
        std::string field;
        std::getline(in_pipes, line);
        while (std::getline(in_pipes, line)) {
            std::istringstream iss(line);
            PipeContext pipeContext;

            std::getline(iss, pipeContext.service_point_A, ',');
            std::getline(iss, pipeContext.service_point_B, ',');
            std::getline(iss, field, ',');
            std::from_chars(field.data(), field.data() + field.size(), pipeContext.capacity);
            std::getline(iss, field, ',');
            pipeContext.direction = (field == "1");

            pipe_info_container.push_back(pipeContext);
        }

        return 0;
    }

    int fetch_reservoirs(const std::string& reservoir_file_path, std::vector<ReservoirContext>& reservoir_info_container) {
        std::ifstream in_reservoirs(reservoir_file_path);
        if (!in_reservoirs.is_open())
            return 1;

        std::string line;
        std::string field;
        std::getline(in_reservoirs, line);
        while (std::getline(in_reservoirs, line)) {
            std::istringstream iss(line);
            ReservoirContext reservoirContext;

            std::getline(iss, reservoirContext.reservoir, ',');
            std::getline(iss, reservoirContext.municipality, ',');
            std::getline(iss, field, ',');
            std::from_chars(field.data(), field.data() + field.size(), reservoirContext.id);
            std::getline(iss, reservoirContext.code, ',');
            std::getline(iss, field, ',');
            std::from_chars(field.data(), field.data() + field.size(), reservoirContext.max_delivery);

            reservoir_info_container.push_back(reservoirContext);
        }

        return 0;
    }

    int fetch_stations(const std::string& station_file_path, std::vector<StationContext>& station_info_container) {
        std::ifstream in_stations(station_file_path);
        if (!in_stations.is_open())
            return 1;

        std::string line;
        std::string field;
        std::getline(in_stations, line);
        while (std::getline(in_stations, line)) {
            std::istringstream iss(line);
            StationContext stationContext;

            std::getline(iss, field, ',');
            std::from_chars(field.data(), field.data() + field.size(), stationContext.id);
            std::getline(iss, stationContext.code, ',');

            station_info_container.push_back(stationContext);
        }

        return 0;
    }

    int fetch_data(const std::string& city_file_path, std::vector<CityContext>& city_info_container,
                   const std::string& pipe_file_path, std::vector<PipeContext>& pipe_info_container,
                   const std::string& reservoir_file_path, std::vector<ReservoirContext>& reservoir_info_container,
                   const std::string& station_file_path, std::vector<StationContext>& station_info_container) {
        if (fetch_cities(city_file_path, city_info_container)) return 1;
        if (fetch_pipes(pipe_file_path, pipe_info_container)) return 2;
        if (fetch_reservoirs(reservoir_file_path, reservoir_info_container)) return 3;
        if (fetch_stations(station_file_path, station_info_container)) return 4;

        return 0;
    }

    void build_graph(Graph& graph,
                   const std::vector<CityContext>& city_info_container,
                   const std::vector<ReservoirContext>& reservoir_info_container,
                   const std::vector<StationContext>& station_info_container,
                   const std::vector<PipeContext>& pipe_info_container) {
        for (const CityContext& context: city_info_container) {
            graph.addVertex<CityContext, City>(context);
        }
        for (const ReservoirContext& context: reservoir_info_container) {
            graph.addVertex<ReservoirContext, Reservoir>(context);
        }
        for (const StationContext& context: station_info_container) {
            graph.addVertex<StationContext, Station>(context);
        }
        for (const PipeContext& context: pipe_info_container) {
            if (context.service_point_A[0] == 'R' && context.service_point_B[1] == 'S') {
                graph.addPipe<ReservoirContext, Reservoir, StationContext, Station>(context.service_point_A, context.service_point_B, context);
            } else if (context.service_point_A[1] == 'S' && context.service_point_B[0] == 'C') {
                graph.addPipe<StationContext, Station, CityContext, City>(context.service_point_A, context.service_point_B, context);
            } else if (context.service_point_A[1] == 'S' && context.service_point_B[1] == 'S') {
                graph.addPipe<StationContext, Station, StationContext, Station>(context.service_point_A, context.service_point_B, context);
            }
        }
    }
}