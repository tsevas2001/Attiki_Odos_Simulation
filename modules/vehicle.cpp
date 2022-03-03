#include "../headers/vehicle.h"

Vehicle::Vehicle(int node, int segm) : exitNode{node}, currentSegm{segm}
{
    ready = false; // initialize readiness with false for vehicle
}

bool Vehicle::isReady()
{
    return ready;
}

int Vehicle::getExitNode()
{
    return exitNode;
}

void Vehicle::prepare()
{
    ready = true;
}

void Vehicle::enter(int segm)
{
    currentSegm = segm;
}

void Vehicle::ChangeSeg()
{
    currentSegm++;
    ready = false;
}

states Vehicle::progress()
{
    if (ready == false)
        return FAIL;
    ChangeSeg();
    if (currentSegm == exitNode)
        return EXIT;

    return SUCCESS;
}

Vehicle::~Vehicle()
{
    cout << "Vehicle destroyed successfully!" << endl;
}