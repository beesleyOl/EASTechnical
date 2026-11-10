#include <string>

// Route represents a link between two locations with a specified distance

class route {
    public:

    //Constructor used to create a route object
    route(
        const std::string& destination,
        int distance);

    // Returns the destination location name
    std::string getDestination() const;
    
    // Returns distance to the destination
    int getDistance() const;

    private:
        // Name of destination location
        std::string destination;
        
        // Distance to location
        int distance;
};