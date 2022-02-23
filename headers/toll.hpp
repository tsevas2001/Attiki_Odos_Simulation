#ifndef toll_HPP
#define toll_HPP
#include "main.hpp"
#include "entrance.hpp"

class Toll
{
public:
    Toll(const vector<Vehicle *> &);
    virtual ~Toll();

    void enter(Vehicle *);
    vector<Vehicle *> exit(int); // amount of vehicles which are about to exit from toll

    int getWaitingVehicles();

protected:
    vector<Vehicle *> waitingVehicles;
};

class eToll : public Toll
{

public:
    eToll(const std::vector<Vehicle *> &);
    ~eToll();
};

class collectorToll : public Toll
{

public:
    collectorToll(const std::vector<Vehicle *> &);
    ~collectorToll();
};

#endif