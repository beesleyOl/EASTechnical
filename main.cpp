#include <iostream>

#include "location.h"
#include "route.h"
#include "pathfinder.h"
#include "fileLoader.h"

int main()
{
    fileLoader loader;

    graph routeNetwork =
        loader.loadGraph(
            "routes.txt");
    
    pathfinder finder;
    
    std::string startLocation;
    std::string destinationLocation;

    std::cout << "Enter start location: ";
    std::getline(
        std::cin,
        startLocation);
    
    if (!routeNetwork.hasLocation(startLocation))
    {
        std::cout
            << "The start location you entered is not valid: "
            << startLocation
            << '\n';
        
        return 1;
    }
    std::cout << "Enter destination: ";
    std::getline(
        std::cin,
        destinationLocation);
    
    if (!routeNetwork.hasLocation(destinationLocation))
    {
        std::cout
            << "The end location you entered is not valid: "
            << destinationLocation
            << '\n';
        
        return 1;
    }

    pathresult result = 
        finder.findShortestPath(
            routeNetwork,
            startLocation,
            destinationLocation);
    
    std::cout
        << "Shortest Distance: "
        << result.getDistance()
        << " km\n\n";

    std::cout << "Route:\n";

    for (const auto& stop :
         result.getRoute())
    {
        std::cout
            << stop
            << '\n';
    }

    return 0;

}
