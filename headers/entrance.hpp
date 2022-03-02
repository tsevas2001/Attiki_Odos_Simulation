#ifndef ENTRANCE_HPP
#define ENTRANCE_HPP
#include "../main.hpp"
#include "segment.hpp"
#include "toll.hpp"

class Entrance
{
private:
    const int nodeNum;
    vector<CollectorToll *> collectorTolls;
    vector<EToll *> eTolls;
    int totalCap; // added here to help with some checks
    static int K;
    int nSegs;

public:
    Entrance(int, int, int, int);
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