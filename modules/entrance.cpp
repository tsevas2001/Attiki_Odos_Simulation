#include "../headers/entrance.hpp"
#include "../main.hpp"

int Entrance::K = 0;

Entrance::Entrance(int n, int manned, int unmanned) : nodeNum(n)
{
    cout << "Creating Gate..." << endl;

    for (int i = 0; i < manned; i++)
    {
        int carsToEnter = rand() % 5 + 1;

        vector<Vehicle *> vehicles = Vehicle::randVehicles(carsToEnter, this->nodeNum);
        this->collectorTolls.push_back(new CollectorToll(vehicles));
    }

    for (int i = 0; i < unmanned; i++)
    {
        int carsToEnter = rand() % 5 + 1;
        vector<Vehicle *> vehicles = Vehicle::randVehicles(carsToEnter, this->nodeNum);
        this->eTolls.push_back(new EToll(vehicles));
    }

    this->totalCap = 3 * Entrance::K;

    cout << "Gate Created!" << endl;
}

Entrance::~Entrance()
{
    cout << "Destroying an entrance..." << endl;
    for (CollectorToll *booth : this->collectorTolls)
        delete booth;

    for (EToll *booth : this->eTolls)
        delete booth;
}

vector<Vehicle *> Entrance::operate(int segmentCap)
{

    cout << "Operating entrance..." << endl;
    cout << "Removing " << segmentCap << " cars from toll booths..." << endl;
    vector<Vehicle *> removedCars = this->exit(segmentCap);

    cout << "Vehicles removed from toll booths." << endl;

    if (segmentCap >= this->totalCap)
        this->increaseCap();
    else
        this->decreaseCap();

    this->enter();

    return removedCars;
}

void Entrance::increaseCap()
{
    totalCap = totalCap + 3;
}

void Entrance::decreaseCap()
{
    // this->totalCap = this->totalCap - 3;
    totalCap = totalCap - 3;
}

// Lets min(segmentCap,totalCap) cars through the entrance into the next segment
vector<Vehicle *> Entrance::exit(int segmentCap)
{
    vector<Vehicle *> vehiclesToRemove;

    if (this->totalCap < segmentCap)
    {
        segmentCap = this->totalCap;
    }

    // 1 thirdof the total load is handled by the manned Toll Booths
    int handledByManned = min<int>(segmentCap / 3, Entrance::K);
    cout << handledByManned << " cars will be handled by manned booths" << endl;
    // 2 thirds(2K) are handled by the unmanned Toll Booths
    int handledByUnmanned = min<int>(segmentCap - handledByManned, 2 * Entrance::K); //=2segmentcap/3, most of the load goes to unmanned booths
    cout << handledByUnmanned << " cars will be handled by unmanned booths" << endl;

    // The load a single booth handles is, at maximum, singleLoad + 1
    int singleLoad = handledByManned / this->collectorTolls.size();
    cout << "Each manned booth will handle at least " << singleLoad << " vehicles." << endl;
    int leftovers = handledByManned % this->collectorTolls.size();
    cout << leftovers << " leftover cars, will each be handled by a different booth." << endl;

    // For every booth, if we have leftovers, we make is handle its load + 1 more car.
    // If we dont, it just handles its own load
    cout << "Removing cars from manned booths..." << endl;
    for (CollectorToll *booth : this->collectorTolls)
    {
        vector<Vehicle *> vs;
        if (0 != leftovers)
        {
            cout << "Removing " << singleLoad << " cars + 1 leftover car..." << endl;
            vs = booth->exit(singleLoad + 1);
            leftovers--;
            cout << "Cars removed!" << endl;
        }
        else if (singleLoad != 0)
        {
            cout << "Removing " << singleLoad << " cars..." << endl;
            vs = booth->exit(singleLoad);
            cout << "Cars removed!" << endl;
        }
        for (Vehicle *vehicle : vs)
        {
            cout << "Pushing removed vehicles through..." << endl;
            vehiclesToRemove.push_back(vehicle);
            cout << "Vehicles from this booth passed!" << endl;
        }
    }

    singleLoad = handledByUnmanned / this->eTolls.size();
    cout << "Each unmanned booth will handle at least " << singleLoad << " vehicles." << endl;
    leftovers = handledByUnmanned % this->eTolls.size();
    cout << leftovers << " leftover cars, will each be handled by a different booth." << endl;

    cout << "Removing cars from unmanned booths..." << endl;
    for (EToll *booth : this->eTolls)
    {
        vector<Vehicle *> vs;
        if (0 != leftovers)
        {
            cout << "Removing " << singleLoad << " cars + 1 leftover car..." << endl;
            vs = booth->exit(singleLoad + 1);
            leftovers--;
            cout << "Cars removed!\n";
        }
        else if (singleLoad != 0)
        {
            cout << "Removing " << singleLoad << " cars..." << endl;
            vs = booth->exit(singleLoad);
            cout << "Cars removed!\n";
        }
        else
        {
            cout << "No cars to push from this toll booth\n";
        }
        cout << "Pushing " << vs.size() << " removed vehicles through..." << endl;
        for (Vehicle *vehicle : vs)
        {
            vehiclesToRemove.push_back(vehicle);
        }
        cout << "Vehicles from this booth passed!" << endl;
    }
    cout << "Passing vehicles to the segment..." << endl;

    return vehiclesToRemove;
}

// Adds vehicles to the entrance's TollBooths
void Entrance::enter()
{
    for (CollectorToll *booth : this->collectorTolls)
    {
        int amount = rand() % 3;
        vector<Vehicle *> vehiclesToAdd = Vehicle::randVehicles(amount, this->nodeNum);

        for (Vehicle *vehicle : vehiclesToAdd)
            booth->enter(vehicle);
    }
    for (EToll *booth : this->eTolls)
    {
        int amount = rand() % 3;
        vector<Vehicle *> vehiclesToAdd = Vehicle::randVehicles(amount, this->nodeNum);

        for (Vehicle *vehicle : vehiclesToAdd)
            booth->enter(vehicle);
    }
}

int Entrance::waitingVehicles()
{
    int size = 0;
    for (CollectorToll *booth : this->collectorTolls)
        size += booth->getWaitingVehicles();

    for (EToll *booth : this->eTolls)
        size += booth->getWaitingVehicles();

    return size;
}

int Entrance::getNodeNum()
{
    return nodeNum;
}
