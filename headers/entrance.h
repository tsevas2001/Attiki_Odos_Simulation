#ifndef ENTRANCE_H
#define ENTRANCE_H
#include "../main.h"
#include "toll.h"

class Entrance
{
private:
    const int nodeNum;
    vector<CollectorToll *> collectorTolls;
    vector<EToll *> eTolls;
    int totalCap; // added here to help with some checks
    int K;
    int nSegs = 0;

public:
    Entrance(int, int, int, int, int);
    ~Entrance();
    void enter();
    vector<Vehicle *> exit(int);
    void increaseCap(); // increase capacity
    void decreaseCap(); // decrease capacity
    vector<Vehicle *> operate(int);

    int getNodeNum();
    int waitingVehicles();
    // static void setK(int Kval) { K = Kval; } // initialiser
};

#endif