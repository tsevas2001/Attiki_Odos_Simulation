#include "../headers/entrance.h"
#include "../main.h"

Entrance::Entrance(int n, int collectorNum, int eNum, int Segs, int k) : nodeNum(n), nSegs(Segs), K(k)
{
    cout << "Creating Gate..." << endl;

    for (int i = 0; i < collectorNum; i++)
    {
        int vehiclesRandNum = rand() % 5 + 1; // random vehicles which are about to enter
        vector<Vehicle *> vehicles;

        int exitNode = 0;
        for (int i = 0; i < vehiclesRandNum; i++)
        {
            if ((nSegs - 1 - nodeNum) != 0)
                exitNode = (rand() % (nSegs - 1 - nodeNum)) + nodeNum;
            else
                exitNode = nodeNum;

            Vehicle *vehicle = new Vehicle(exitNode, -1);
            vehicles.push_back(vehicle);
        }
        this->collectorTolls.push_back(new CollectorToll(vehicles));
    }

    for (int i = 0; i < eNum; i++)
    {
        int vehiclesRandNum = rand() % 5 + 1;
        vector<Vehicle *> vehicles;

        int exitNode = 0;
        for (int i = 0; i < vehiclesRandNum; i++)
        {
            if ((nSegs - 1 - nodeNum) != 0)
                exitNode = (rand() % (nSegs - 1 - nodeNum)) + nodeNum;
            else
                exitNode = nodeNum;

            Vehicle *vehicle = new Vehicle(exitNode, -1);
            vehicles.push_back(vehicle);
        }
        this->eTolls.push_back(new EToll(vehicles));
    }

    this->totalCap = 3 * K;

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
    totalCap = totalCap - 3;
}

vector<Vehicle *> Entrance::exit(int segmentCap)
{
    vector<Vehicle *> vehiclesToRemove;

    if (this->totalCap < segmentCap)
        segmentCap = this->totalCap;

    int vehiclesByCollector = min<int>(segmentCap / 3, K); // take the smallest amount between capacity divided by 3 and K
    cout << "Vehicles which will be handled by tolls with collector: " << vehiclesByCollector << endl;
    // 2 thirds(2K) are handled by the unmanned Toll Booths
    int vehiclesByEtoll = min<int>(segmentCap - vehiclesByCollector, 2 * K); //=2segmentcap/3, most of the load goes to unmanned booths
    cout << "Vehicles which will be handled by electronic tolls: " << vehiclesByEtoll << endl;

    int numOfCollectorVehicles = vehiclesByCollector / this->collectorTolls.size();
    int numOfRemainingVehicles = vehiclesByCollector % this->collectorTolls.size();

    for (CollectorToll *booth : this->collectorTolls) // for each booth  we have two cases: We have raiming vehicles or we dont have
    {
        vector<Vehicle *> vs;
        if (0 != numOfRemainingVehicles)
        {
            cout << "Removing vehicles on collector toll: " << numOfCollectorVehicles << endl;
            vs = booth->exit(numOfCollectorVehicles + 1);
            numOfRemainingVehicles--;
        }
        else if (numOfCollectorVehicles != 0)
        {
            cout << "Vehicles which are about to be removed: " << numOfCollectorVehicles << endl;
            vs = booth->exit(numOfCollectorVehicles);
        }
        for (Vehicle *vehicle : vs)
        {
            cout << "Pushing removed vehicles through..." << endl;
            vehiclesToRemove.push_back(vehicle);
            cout << "Vehicles from this booth passed!" << endl;
        }
    }

    numOfCollectorVehicles = vehiclesByEtoll / this->eTolls.size();
    numOfRemainingVehicles = vehiclesByEtoll % this->eTolls.size();

    cout << "Removing cars from unmanned booths..." << endl;
    for (EToll *booth : this->eTolls)
    {
        vector<Vehicle *> vehicles;
        if (0 != numOfRemainingVehicles)
        {
            cout << "Removing vehicles on collector toll: " << numOfCollectorVehicles << endl;
            vehicles = booth->exit(numOfCollectorVehicles + 1);
            numOfRemainingVehicles--;
        }
        else if (numOfCollectorVehicles != 0)
        {
            cout << "Vehicles which are about to be removed: " << numOfCollectorVehicles << endl;
            vehicles = booth->exit(numOfCollectorVehicles);
        }
        else
        {
            cout << "There are NO vehicles to push" << endl;
        }

        for (Vehicle *vehicle : vehicles) // here we are passing the vehicles from the currrent booth
            vehiclesToRemove.push_back(vehicle);
    }
    cout << "Passing vehicles to the segment..." << endl;

    return vehiclesToRemove;
}

void Entrance::enter()
{
    for (CollectorToll *booth : this->collectorTolls)
    {
        int amount = rand() % 3; // set randomly the amount
        vector<Vehicle *> vehiclesToAdd;

        int exitNode = 0;
        for (int i = 0; i < amount; i++)
        {
            if ((nSegs - 1 - nodeNum) != 0)
                exitNode = (rand() % (nSegs - 1 - nodeNum)) + nodeNum;
            else
                exitNode = nodeNum;

            Vehicle *vehicle = new Vehicle(exitNode, -1);
            vehiclesToAdd.push_back(vehicle);
        }

        for (Vehicle *vehicle : vehiclesToAdd)
            booth->enter(vehicle);
    }
    for (EToll *booth : this->eTolls)
    {
        int amount = rand() % 3;

        vector<Vehicle *> vehiclesToAdd;

        int exitNode = 0;
        for (int i = 0; i < amount; i++)
        {

            if ((nSegs - 1 - nodeNum) != 0)
                exitNode = (rand() % (nSegs - 1 - nodeNum)) + nodeNum;
            else
                exitNode = nodeNum;

            Vehicle *vehicle = new Vehicle(exitNode, -1);
            vehiclesToAdd.push_back(vehicle);
        }

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
