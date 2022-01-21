#ifndef VEHICLE_HPP
#define VEHICLE_HPP
#include "main.hpp"
#include "segment.hpp"

class Vehicle
{
private:
    int id;
    int indication;  // shows in which segment of vehicle is the vehicle
    string exitNode; // destinationo of vehicle
    Segment currentSegm;

public:
    Vehicle(int, string, Segment);
    void getInfo();
    void setInfo(string, Segment);
    ~Vehicle();
};

#endif