#ifndef toll_H
#define toll_H
#include "../main.h"
#include "vehicle.h"

class Toll
{
private:
    vector<Vehicle *> waitingVehicles;

public:
    Toll(const vector<Vehicle *> &);
    virtual ~Toll();
    void enter(Vehicle *);
    vector<Vehicle *> exit(int); // amount of vehicles which are about to exit from toll
    int getWaitingVehicles();
};

class EToll : public Toll
{
public:
    EToll(const vector<Vehicle *> &);
    ~EToll();
};

class CollectorToll : public Toll
{
public:
    CollectorToll(const vector<Vehicle *> &);
    ~CollectorToll();
};

#endif