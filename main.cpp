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
    
    std::cout << "Before pathfinder\n";

    pathresult result =
        finder.findShortestPath(
            routeNetwork,
            "Cardiff",
            "Bristol");

    std::cout << "After pathfinder\n";
    
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
