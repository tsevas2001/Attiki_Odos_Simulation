#include "../headers/toll.h"
#include "../main.h"

Toll::Toll(const vector<Vehicle *> &vehicles)
{
    for (Vehicle *vehicle : vehicles)
        this->enter(vehicle);
}

Toll::~Toll()
{
    for (Vehicle *vehicle : this->waitingVehicles)
        delete vehicle;
}

void Toll::enter(Vehicle *vehicle)
{
    this->waitingVehicles.push_back(vehicle);
}

vector<Vehicle *> Toll::exit(int vehiclesToExit)
{
    if (vehiclesToExit > this->waitingVehicles.size()) // amount of vehicles which are about to exit are more than waiting vehicles
    {
        cout << "Unfortunately there are not enough vehicles waiting on queue" << endl;
        vehiclesToExit = this->waitingVehicles.size();
    }
    cout << "Vehicles which are about to exit: " << vehiclesToExit << endl;

    vector<Vehicle *> currentVehiclesToExit;
    for (int i = 0; i < vehiclesToExit; i++) // here we use "first in first out" modeling
    {
        cout << "Vehicle[" << i << "]" << endl;
        Vehicle *v = this->waitingVehicles[0];
        currentVehiclesToExit.push_back(v);
        this->waitingVehicles.erase(this->waitingVehicles.begin());
        cout << "The vehicle just erased.\n"
             << endl;
    }
    return currentVehiclesToExit;
}

int Toll::getWaitingVehicles()
{
    return this->waitingVehicles.size();
}

CollectorToll::CollectorToll(const std::vector<Vehicle *> &vehicles) : Toll(vehicles)
{
    cout << "Toll with collector created" << endl;
}

CollectorToll::~CollectorToll()
{
    cout << "Toll with collector destroyed" << endl;
}

EToll::EToll(const std::vector<Vehicle *> &vehicles) : Toll(vehicles)
{
    cout << "E-Toll created" << endl;
}

EToll::~EToll()
{
    cout << "E-Toll destroyed" << endl;
}
