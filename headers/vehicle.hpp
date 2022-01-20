#ifndef VEHICLE_HPP
#define VEHICLE_HPP
#include "main.hpp"

class Vehicle
{
private:
    int id;
    int indication;
    string currentNode;
    Segment currentSegm;

public:
    Vehicle(int, string, Segment);
    void getInfo();
    void setInfo(string, Segment);
    ~Vehicle();
};

#endif