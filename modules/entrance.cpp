#include "../headers/entrance.hpp"

Entrance::Entrance(string nodeN, vector<Tool> collect, vector<Tool> etool, int cap) : nodeName{nodeN}, collectorTool{collect}, eTool{etool}, capacity{cap}
{
    cout << "Entrance opened successfully!" << endl;
}

Entrance::~Entrance()
{
    cout << "Entrance destroyed successfully!" << endl;
}