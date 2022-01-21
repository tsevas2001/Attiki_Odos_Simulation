#ifndef HIGHWAY_HPP
#define HIGHWAY_HPP
#include "main.hpp"
#include "segment.hpp"

class Highway
{
private:
    vector<Segment> nSegs;
    int totalVehicles;

public:
    Highway(int, vector<Segment>);
    void operate();
    ~Highway();
};

#endif