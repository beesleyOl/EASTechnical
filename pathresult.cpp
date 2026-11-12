#include "pathresult.h"

void pathresult::setDistance(int distance)
{
    totalDistance = distance;
}

void pathresult::setRoute(
    const std::vector<std::string>& route)
{
    this->route = route;
}

int pathresult::getDistance() const
{
    return totalDistance;
}

const std::vector<std::string>&
pathresult::getRoute() const
{
    return route;
}