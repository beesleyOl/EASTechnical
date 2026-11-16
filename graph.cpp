#include "graph.h"

// Stores the location using its name as the lookup key
void graph::addLocation(
    const location& location)
{
    locations.insert(
        { location.getName(), location});
}

// Checks whether a location exists in the graph
bool graph::hasLocation(
    const std::string& name) const
    {
        return locations.find(name)
            != locations.end();   
    };

// Gets the location using its name
const location& graph::getLocation(
    const std::string& name) const
{
        return locations.at(name);
}

// Creates a bidrectional connection, as it allows the route to be travelled in either direction
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