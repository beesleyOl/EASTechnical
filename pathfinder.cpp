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

    std::priority_queue<
        QueueNode,
        std::vector<QueueNode>,
        std::greater<QueueNode>
    > queue;

    distances[start] = 0;

    queue.push(
        {
            start,
            0
        });
    
    while (!queue.empty())
    {
        QueueNode currentQueueNode =
            queue.top();
        
        queue.pop();

        std::string currentLocation = 
            currentQueueNode.location;
        
        if (visited.count(currentLocation))
        {
            continue;
        }

        visited.insert(currentLocation);

        if(currentLocation ==
            destination)
        {
            break;
        }

        const location& currentNode = 
            graph.getLocation(
                currentLocation);
        
        for (const route& r :
            currentNode.getRoutes())
        {
            int newDistance = 
                distances[currentLocation]
                + r.getDistance();
            
            if (
                !distances.count(
                    r.getDestination())
                ||
                newDistance
                    <
                distances[
                    r.getDestination()
                ])
            {
                distances[
                    r.getDestination()
                ] = newDistance;

                previous[
                    r.getDestination()
                ] = currentLocation;

                queue.push(
                {
                    r.getDestination(),
                    newDistance
                });
            }
        }

    }

    if (!distances.count(destination))
    {
        return result;
    }

    std::vector<std::string> path;

    std::string current = 
        destination;
    
    while (current != start)
    {        
        path.push_back(current);

        current =
            previous[current];
    }

    path.push_back(start);

    std::reverse(
        path.begin(),
        path.end());

    result.setDistance(
        distances[destination]);

    result.setRoute(path);

    return result;
}