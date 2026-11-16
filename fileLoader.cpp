#include "fileLoader.h"

#include <iostream>
#include <fstream>
#include <sstream>

graph fileLoader::loadGraph(
    const std::string& filename)
{
    graph routeNetwork;

    // Open the route destination file, with the expected format being:
    // From,To,Distance
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
    // Skips blank lines to allow clear organisation in data file.
    if (line.empty())
    {
        continue;
    }

    // Splits the CSV line into its desired components
    std::stringstream ss(line);

    std::string from;
    std::string to;
    std::string distanceString;

    std::getline(ss, from, ',');
    std::getline(ss, to, ',');
    std::getline(ss, distanceString, ',');

    // SKip invalid records that are missing fields.
    if (from.empty() ||
        to.empty() ||
        distanceString.empty())
    {
        std::cout
            << "Skipping invalid line: "
            << line
            << '\n';

        continue;
    }

    // COnverts distance from a string to an interger
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

    // Creating locations if they have not been added already
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

    //Creating a route between the two locations with the specified distance 
    routeNetwork.addConnection(
        from,
        to,
        distance);
}

    return routeNetwork;
}