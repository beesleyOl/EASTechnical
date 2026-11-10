#include <string>
#include <vector>

#include "route.h" 

// Location represents a place within the route system
class location{
    public:

        // Constructo to create a location
        location(const std::string& name);

        // Returns locations names
        std::string getName() const;

        // Adds a route related to this location
        void addRoute(const route& route);

        // Returns all routes related to this location
        const std::vector<route>& getRoutes() const;
    
    private:
        // Name of location
        std::string name;

        // All out going routes of the location
        std::vector<route> routes;    
};