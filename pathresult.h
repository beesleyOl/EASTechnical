#pragma once

#include <string>
#include <vector>

// Represents the result returned by the pathfinding algortithm

class pathresult
{
public:

    // Stores the final route distance
    void setDistance(int distance);

    // Stores the ordered route locations
    void setRoute(
        const std::vector<std::string>& route);

    // Returns the total route distance
    int getDistance() const;

    // Returns the calculated route
    const std::vector<std::string>&
    getRoute() const;

private:

    // Total distance of the shortest route
    int totalDistance = 0;
    
    // Ordered list of locations from start to destination
    std::vector<std::string> route;
};