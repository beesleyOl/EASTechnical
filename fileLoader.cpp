#include "fileLoader.h"

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
        std::stringstream ss(line);

        std::string from;
        std::string to;
        std::string distanceString;
        
        std::getline(
            ss,
            from,
            ',');
        
        std::getline(
            ss,
            to,
            ',');

        std::getline(
            ss,
            distanceString,
            ',');    
        
        int distance = 
            std::stoi(distanceString);
        
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