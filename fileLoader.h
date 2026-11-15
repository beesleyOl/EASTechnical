#pragma once

#include <string>

#include "graph.h"

class fileLoader
{

public:
    graph loadGraph(
        const std::string& filename);
};