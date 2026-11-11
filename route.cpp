#include "route.h" 

// Constructor definiton
// Initializer list directly initializes member variables when object is created.
route::route(
    const std::string& destination,
    int distance)
    : destination(destination),
    distance(distance)

// No addtional setup required
{
}

// Returns the destination location name
std::string route::getDestination()const
{
    return destination;
}

// Returns the route distance
int route::getDistance() const
{
    return distance;
}