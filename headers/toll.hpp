#ifndef toll_HPP
#define toll_HPP
#include "../main.hpp"
#include "entrance.hpp"

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