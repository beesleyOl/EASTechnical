#include "graph.h"

void graph::addLocation(
    const location& location)
{
    locations.insert(
        { location.getName(), location});
}

bool graph::hasLocation(
    const std::string& name) const
    {
        return locations.find(name)
            != locations.end();   
    };

const location& graph::getLocation(
    const std::string& name) const
{
        return locations.at(name);
}

void graph::addConnection(
    const std::string& from,
    const std::string& to,
    int distance)
{
    locations.at(from)
        .addRoute(route(to,distance));
    
    locations.at(to)
        .addRoute(route(from, distance));
}