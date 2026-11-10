#include "location.h"

// Constructor definition
// Initializes the location name when the object is created
location::location(
    const std::string& name)
    : name(name)
// No addtional setup required
{
}

// Returns the location name
std::string location::getName() const
{
    return name;
}

// Adds a reoute to the routes vector,
// push_back() appends an element to the end of a vector
void location::addRoute(
    const route& route)
{
    routes.push_back(route);
}

// Returns all routes connected to this location
// Returning a const reference avoids copying the entire vector and prevents modification
const std::vector<route>&
location::getRoutes() const
{
    return routes;
}
