#ifndef HIGHWAY_HPP
#define HIGHWAY_HPP
#include "main.hpp"
#include "segment.hpp"

class Highway
{
private:
    vector<Segment*> segments;
    int totalVehicles;
    int nSegs;

public:
    Highway();
    void operate();
    void set(int);
    void print();
    ~Highway();
};

#endif