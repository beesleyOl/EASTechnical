#include <string>

#include "graph.h"
#include "pathresult.h"

class pathfinder
{
public:
    pathresult findShortestPath(
        const graph& graph,
        const std::string& start,
        const std::string& destination);
};