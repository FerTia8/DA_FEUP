//
// Created by TiagoF on 3/17/2024.
//

#include "Reservoir.h"

Reservoir::Reservoir(const ReservoirContext &context)
    : Vertex(context.id, context.code), reservoir(context.reservoir), municipality(context.municipality), max_delivery(context.max_delivery) {}

Reservoir::Reservoir(std::string reservoir, std::string municipality, unsigned int id, std::string code, unsigned int max_delivery)
    : Vertex(id, std::move(code)), reservoir(std::move(reservoir)), municipality(std::move(municipality)), max_delivery(max_delivery) {}

const std::string &Reservoir::getReservoir() const {
    return reservoir;
}

const std::string &Reservoir::getMunicipality() const {
    return municipality;
}

unsigned int Reservoir::getMaxDelivery() const {
    return max_delivery;
}

