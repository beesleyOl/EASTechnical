#pragma once

#include <string>
#include <vector>

class pathresult
{
public:
    void setDistance(int distance);

    void setRoute(
        const std::vector<std::string>& route);

    int getDistance() const;

    const std::vector<std::string>&
    getRoute() const;

private:
    int totalDistance = 0;

    std::vector<std::string> route;
};