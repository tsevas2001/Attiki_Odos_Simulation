#include "../headers/tool.hpp"

Tool::Tool(vector<Vehicle> vehs) : waitingVehicles{vehs}
{
    cout << "Tool created successfully!" << endl;
}

Tool::~Tool()
{
    cout << "Tool destroyed successfully!" << endl;
}