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
    void enter();
    void exit();
    void pass();
    int get_no_of_vehicles();
    ~Highway();
};

#endif