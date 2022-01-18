#include "main.hpp"
#include "entrance.hpp"

using namespace std;

class Tool : public Entrance
{
private:
    vector<Vehicle> waitingVehicles;

public:
    Tool();
    void addVehicles();
    void removeVehicles();
    ~Tool();
};