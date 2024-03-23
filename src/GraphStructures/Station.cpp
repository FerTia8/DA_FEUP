#include "Station.h"

Station::Station(const StationContext &context) : Vertex(context.id, context.code) {}

Station::Station(unsigned int id, std::string code) : Vertex(id, std::move(code)) {}
