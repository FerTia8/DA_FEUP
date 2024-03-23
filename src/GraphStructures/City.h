//
// Created by TiagoF on 3/17/2024.
//

#ifndef PROJECT_1_CITY_H
#define PROJECT_1_CITY_H

#include <string>
#include "Vertex.h"
#include "Contexts/Contexts.h"

class City: public Vertex {
public:
    explicit City(const CityContext& context);
    City(std::string name, unsigned int id, std::string code, double demand, unsigned int population);

    const std::string& getName() const;
    double getDemand() const;
    unsigned int getPopulation() const;

private:
    std::string name;
    double demand;
    unsigned int population;
};


#endif //PROJECT_1_CITY_H
