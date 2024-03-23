//
// Created by TiagoF on 3/17/2024.
//

#ifndef PROJECT_1_RESERVOIR_H
#define PROJECT_1_RESERVOIR_H

#include "Vertex.h"
#include "Contexts/Contexts.h"
#include "Station.h"
#include <string>

class Reservoir: public Vertex {
public:
    explicit Reservoir(const ReservoirContext& context);
    Reservoir(std::string reservoir, std::string municipality, unsigned int id, std::string code, unsigned int max_delivery);

    const std::string& getReservoir() const;
    const std::string& getMunicipality() const;
    unsigned int getMaxDelivery() const;

private:
    std::string reservoir;
    std::string municipality;
    unsigned int max_delivery; // m3/sec
};


#endif //PROJECT_1_RESERVOIR_H
