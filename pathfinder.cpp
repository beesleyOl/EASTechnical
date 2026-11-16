#include <iostream>

#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <vector>
#include <algorithm>
#include <limits>

#include "pathfinder.h"

// Helper structure used by Dijkstra's algorithm
// Stores a location and the shortest known distance to that location
struct QueueNode
{
    std::string location;
    int distance;

    // Allows priority queue to prioritse nodes with shortest distance
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

    // Stores shortest known distances to each location
    std::unordered_map<
        std::string,
        int
    > distances;

    // Stores previous location on the shortest path
    std::unordered_map<
        std::string,
        std::string
    > previous;

    // Tracks locations that have already been explored
    std::unordered_set<
        std::string
    > visited;

    // Priorty queue always returns the location with the lowest known distance.
    std::priority_queue<
        QueueNode,
        std::vector<QueueNode>,
        std::greater<QueueNode>
    > queue;

    // Distance from start to itself is zero
    distances[start] = 0;

    queue.push(
        {
            start,
            0
        });
    
    // Continue untill there are no locations left to explore
    while (!queue.empty())
    {
        QueueNode currentQueueNode =
            queue.top();
        
        queue.pop();

        std::string currentLocation = 
            currentQueueNode.location;
        
        // Ignore locations already processed
        if (visited.count(currentLocation))
        {
            continue;
        }

        visited.insert(currentLocation);

        // Stop once the destination is reached
        if(currentLocation ==
            destination)
        {
            break;
        }

        const location& currentNode = 
            graph.getLocation(
                currentLocation);
        
        // Explore all neighbouring locations
        for (const route& r :
            currentNode.getRoutes())
        {
            int newDistance = 
                distances[currentLocation]
                + r.getDistance();
            
            // Update if a shorter route is found
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

    // If the destination was never reached, no valid route exists.
    if (!distances.count(destination))
    {
        return result;
    }

    std::vector<std::string> path;

    std::string current = 
        destination;
    
    // Reconstruct the path by walking backwards through previous location map
    while (current != start)
    {        
        path.push_back(current);

        current =
            previous[current];
    }

    path.push_back(start);

    // Reverse so the route runs from start to destination
    std::reverse(
        path.begin(),
        path.end());

    // Store the completed route and distance
    result.setDistance(
        distances[destination]);

    result.setRoute(path);

    return result;
}