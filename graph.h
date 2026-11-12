#include <string>
#include <unordered_map>

#include "location.h"

class graph
{
    public:
        void addLocation(const location& location);

        void addConnection(
            const std::string& from,
            const std::string& to,
            int distance);
        
        bool hasLocation(
            const std::string& name) const;
        
        const location& getLocation(
            const std::string& name) const;
        
    private:
            std::unordered_map<
                std::string,
                location
            > locations;
};