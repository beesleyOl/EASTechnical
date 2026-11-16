#pragma once

#include <string>

#include "graph.h"

// Loads location and route information from a text file and builds a graph using it

class fileLoader
{

public:
    // Loads routes from the specified file and returns a populated graph
    graph loadGraph(
        const std::string& filename);
};