#pragma once

#include <string>
#include <unordered_map>

#include "location.h"

// Represents the transport network of locations and routes
class graph
{
    public:
        // Adds location to the graph
        void addLocation(const location& location);

        // Creates a bidrectional route
        void addConnection(
            const std::string& from,
            const std::string& to,
            int distance);
        
        // Checks if a location exists
        bool hasLocation(
            const std::string& name) const;
        
        // Returns a location by name
        const location& getLocation(
            const std::string& name) const;
        
    private:
        // Stores location using their names
        std::unordered_map<
            std::string,
            location
        > locations;
};