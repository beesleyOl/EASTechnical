#pragma once

#include <string>

#include "graph.h"
#include "pathresult.h"
// Uses Dijikstra's shortest path algorithm to find shortest route between two locations
class pathfinder
{
public:

    //Calculates the shortest route between the start and destination location
    pathresult findShortestPath(
        const graph& graph,
        const std::string& start,
        const std::string& destination);
};