#ifndef HIGHWAY_H
#define HIGHWAY_H
#include "../main.h"
#include "segment.h"

class Highway
{
private:
    vector<Segment*> segments; // a vector with all segments of highway
    int totalVehicles;
    int nSegs = 0;

public:
    Highway(int, int, int);
    void operate();
    void set(int);
    void print();
    ~Highway();
};

#endif