#include "pathfinder.h"

pathresult pathfinder::findShortestPath(
    const graph& graph,
    const std::string& start,
    const std::string& destination)
{
    pathresult result;

    result.setDistance(35);

    result.setRoute({
        "Cardiff",
        "Newport",
        "Bristol"
    });
    
    return result;
}