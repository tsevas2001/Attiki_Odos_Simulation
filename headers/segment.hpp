#ifndef SEGMENT_HPP
#define SEGMENT_HPP
#include "main.hpp"
#include "highway.hpp"
#include "vehicle.hpp"
#include "entrance.hpp"

class Segment
{
private:
    Entrance ent;
    vector<Vehicle> vehicles;
    int capacity;
    Segment *next;
    Segment *previous;
    int indication;

public:
    Segment(Entrance, vector<Vehicle>, int, Segment *, Segment *, int);
    void enter();
    void exit();
    void pass();
    int get_no_of_vahicles();
    void print();
    ~Segment();
};

#endif