#ifndef VEHICLE_HPP
#define VEHICLE_HPP
#include "main.hpp"

enum states
{
    SUCCESS,
    FAIL,
    EXIT
};

class Vehicle
{
private:
    const int exitNode; // destination of vehicle
    int currentSegm;
    bool ready;

public:
    Vehicle(int, int);
    bool isReady();
    int getExitNode();
    void prepare();
    void enter(int);
    void ChangeSeg();
    states progress();
    ~Vehicle();
};

#endif