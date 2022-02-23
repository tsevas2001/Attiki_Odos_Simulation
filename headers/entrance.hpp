#ifndef ENTRANCE_HPP
#define ENTRANCE_HPP
#include "main.hpp"
#include "segment.hpp"
#include "toll.hpp"

class Entrance
{
private:
    void addToBooths();
    vector<Vehicle *> removeFromBooths(int);
    void incrementCapacity();
    void decrementCapacity();

    const int node;
    vector<collectorToll *> collectorTolls;
    vector<eToll *> eTolls;

    int totalCap; // added here to help with some checks
    static int K;

public:
    Entrance(int, int, int);
    ~Entrance();

    vector<Vehicle *> operate(int);

    int getNode() const { return node; }
    int waitingVehicles();
    static void setK(int Kval) { K = Kval; } // initialiser
};

#endif