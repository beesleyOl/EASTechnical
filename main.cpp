#include <iostream>

#include "location.h"
#include "route.h"
#include "pathfinder.h"

int main()
{
    graph routeNetwork;

    routeNetwork.addLocation(
        location("Cardiff"));

    routeNetwork.addLocation(
        location("Newport"));

    routeNetwork.addLocation(
        location("Bristol"));
    
    routeNetwork.addLocation(
        location("Swansea"));

    routeNetwork.addConnection(
        "Cardiff",
        "Newport",
        15);

    routeNetwork.addConnection(
        "Newport",
        "Bristol",
        20);
    
    routeNetwork.addConnection(
        "Cardiff",
        "Swansea",
        40);

    routeNetwork.addConnection(
        "Cardiff",
        "Bristol",
        60);
    
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
