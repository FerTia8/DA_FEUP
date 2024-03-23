//
// Created by TiagoF on 3/17/2024.
//

#include "City.h"

City::City(const CityContext &context)
    : Vertex(context.id, context.code), name(context.name), demand(context.demand), population(context.population) {}

City::City(std::string name, unsigned int id, std::string code, double demand, unsigned int population)
    : Vertex(id, std::move(code)), name(std::move(name)), demand(demand), population(population) {}

const std::string& City::getName() const {
    return name;
}

double City::getDemand() const {
    return demand;
}

unsigned int City::getPopulation() const {
    return population;
}