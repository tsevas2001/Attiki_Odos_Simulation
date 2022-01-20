#ifndef TOOL_HPP
#define TOOL_HPP
#include "main.hpp"
#include "entrance.hpp"

class Tool
{
private:
    vector<Vehicle> waitingVehicles;

public:
    Tool(vector<Vehicle>);
    void enter();
    void exit();
    ~Tool();
};

#endif