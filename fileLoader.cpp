#include "fileLoader.h"

#include <iostream>
#include <fstream>
#include <sstream>

graph fileLoader::loadGraph(
    const std::string& filename)
{
    graph routeNetwork;

    std::ifstream file(filename);

    if (!file.is_open())
    {
        throw std::runtime_error(
            "Unable to open file");
    }

    std::string line;

    while (std::getline(
    file,
    line))
{
    if (line.empty())
    {
        continue;
    }

    std::stringstream ss(line);

    std::string from;
    std::string to;
    std::string distanceString;

    std::getline(ss, from, ',');
    std::getline(ss, to, ',');
    std::getline(ss, distanceString, ',');

    if (from.empty() ||
        to.empty() ||
        distanceString.empty())
    {
        std::cout
            << "Skipping malformed line: "
            << line
            << '\n';

        continue;
    }

    int distance;

    try
    {
        distance =
            std::stoi(distanceString);
    }
    catch (const std::exception&)
    {
        std::cout
            << "Skipping invalid line: "
            << line
            << '\n';

        continue;
    }

    if (!routeNetwork.hasLocation(from))
    {
        routeNetwork.addLocation(
            location(from));
    }

    if (!routeNetwork.hasLocation(to))
    {
        routeNetwork.addLocation(
            location(to));
    }

    routeNetwork.addConnection(
        from,
        to,
        distance);
}

    return routeNetwork;
}