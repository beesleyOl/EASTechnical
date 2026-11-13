#include <iostream>

#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <vector>
#include <algorithm>
#include <limits>

#include "pathfinder.h"

struct QueueNode
{
    std::string location;
    int distance;

    bool operator>(const QueueNode& other) const
    {
        return distance > other.distance;
    }
};

pathresult pathfinder::findShortestPath(
    const graph& graph,
    const std::string& start,
    const std::string& destination)
{
    pathresult result;

    std::unordered_map<
        std::string,
        int
    > distances;

    std::unordered_map<
        std::string,
        std::string
    > previous;

    std::unordered_set<
        std::string
    > visited;

    return result;
}