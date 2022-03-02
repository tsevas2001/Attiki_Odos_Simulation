#ifndef SEGMENT_HPP
#define SEGMENT_HPP
#include "main.hpp"
#include "highway.hpp"
#include "vehicle.hpp"
#include "entrance.hpp"

class Segment
{
private:
    Entrance* ent;
    vector<Vehicle*> vehicles;
    Segment* next;
    Segment* previous;
    int capacity;
    int entered;
    int passed;
    int numSeg;
    int percent;

public:
    Segment(Entrance*, int, Segment *, int, int);
    void enter(vector<Vehicle*>);
    void exit();
    void pass();
    void operate();
    void setPrevious(Segment*);
    void setPercent(int);
    void print();
    int get_no_of_vahicles();
    int getReadyVeh();
    ~Segment();
};

#endif