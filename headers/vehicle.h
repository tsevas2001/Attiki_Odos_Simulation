#ifndef VEHICLE_H
#define VEHICLE_H
#include "../main.h"

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