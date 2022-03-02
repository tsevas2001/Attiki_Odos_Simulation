#include "../headers/toll.hpp"
#include "../main.hpp"

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
    // this bit of logic will be left up to the Entrance Class
    //  if(amountNeeded >= this->entryCap){
    //      amountNeeded = this->entryCap;
    //  }
    if (vehiclesToExit > this->waitingVehicles.size()) // amount of vehicles which are about to exit are more than waiting vehicles
    {
        cout << "Not enough cars waiting in toll booth, passing "
             << this->waitingVehicles.size() << " instead of "
             << vehiclesToExit << endl;
        vehiclesToExit = this->waitingVehicles.size();
    }
    cout << "Entered TollBooth::removeFromQueue()" << endl;
    cout << "Attempting to remove " << vehiclesToExit << " vehicles from thi booth" << endl;

    vector<Vehicle *> currentVehiclesToExit;
    for (int i = 0; i < vehiclesToExit; i++) // here we use "first in first out" modeling
    {
        cout << "Chose vehicle " << i << ".\n";
        Vehicle *v = this->waitingVehicles[0];
        currentVehiclesToExit.push_back(v);
        cout << "Erasing vehicle from the toll booth...\n";
        this->waitingVehicles.erase(this->waitingVehicles.begin()); // check later
        cout << "Vehicle erased!\n";
    }

    cout << "Exiting TollBooth:removeFromQueue()" << endl;
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
