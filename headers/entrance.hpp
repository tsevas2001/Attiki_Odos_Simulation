#ifndef ENTRANCE_HPP
#define ENTRANCE_HPP
#include "main.hpp"
#include "segment.hpp"
#include "tool.hpp"

class Entrance
{
private:
    string nodeName;
    vector<Tool> collectorTool;
    vector<Tool> eTool;
    int capacity;

public:
    Entrance(string, vector<Tool>, vector<Tool>, int);
    void exit();
    ~Entrance();
};

#endif