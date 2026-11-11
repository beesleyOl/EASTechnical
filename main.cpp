#include <iostream>

#include "location.h"
#include "route.h"

int main()
{
    location cardiff("Cardiff");

    cardiff.addRoute(route("Newport", 15));
    cardiff.addRoute(route("Swansea", 40));
    cardiff.addRoute(route("Bristol", 60));

    std::cout << "Location: "
              << cardiff.getName()
              << "\n\n";

    std::cout << "Available Routes:\n";

    for (const route& route : cardiff.getRoutes())
    {
        std::cout
            << "Destination: "
            << route.getDestination()
            << " | Distance: "
            << route.getDistance()
            << " km\n";
    }

    return 0;
}
