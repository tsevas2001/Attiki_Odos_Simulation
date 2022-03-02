#include "../headers/segment.h"

Segment::Segment(Entrance *en, int cap, Segment *pre, int id, int nSegs, int percent) : ent{en}, capacity{cap}, previous{pre}, next{nullptr}, percent(percent)
{
    cout << "Creating segment with ID: " << id << endl;

    int alreadyCarsIn = rand() % (capacity * 2 / 3) + 1;

    vector<Vehicle *> addVehs;
    int exitNode = 0;
    for (int i = 0; i < alreadyCarsIn; i++)
    {

        if ((nSegs - 1 - ent->getNodeNum()) != 0)
            exitNode = (rand() % nSegs - 1 - alreadyCarsIn) + alreadyCarsIn;
        else
            exitNode = alreadyCarsIn;

        Vehicle *vehicle = new Vehicle(-1, exitNode);
        addVehs.push_back(vehicle);
    }

    for (Vehicle *veh : addVehs)
        vehicles.push_back(veh);

    entered = 0;
    passed = 0;
    numSeg = id;
    setPrevious(previous);

    cout << "Segment opened successfully!" << endl;
}

void Segment::enter(vector<Vehicle *> addVehicles)
{

    while ((vehicles.size() < capacity) && (addVehicles.size() != 0))
    {

        cout << "Cars where can enter: " << capacity - vehicles.size() << endl;
        cout << "Cars left: " << addVehicles.size() << endl;

        vehicles.push_back(addVehicles[0]);     //  adding the car in the array with every car in the highway
        addVehicles[0]->enter(numSeg);          // let the car to enter
        addVehicles.erase(addVehicles.begin()); // removes the first car from the array
    }
}

void Segment::exit()
{

    for (int i = 0; i < vehicles.size(); i++)
    {
        cout << "Checking car " << i << " to exit..." << endl;

        if ((vehicles[i]->isReady()) && (vehicles[i]->getExitNode() == ent->getNodeNum()))
        {
            Vehicle *removeVeh = vehicles[i];
            vehicles.erase(vehicles.begin() + i);
            cout << "Car " << i << " removed from the highway!" << endl;
            i--;
            delete removeVeh;
        }
        else if (vehicles[i]->getExitNode() == ent->getNodeNum())
        {
            cout << "Car " << i << " not ready yet to exit!" << endl;
        }
        else
        {
            cout << "Car " << i << " will exit at node " << vehicles[i]->getExitNode() << " with ID: " << ent->getNodeNum() << endl;
        }
    }
}

void Segment::pass()
{

    if (next == nullptr)
    {
        cout << "Exiting from the segment!" << endl;
        return;
    }

    vector<Vehicle *> vehToPass;
    vector<Vehicle *> vehToAdd;

    int i;
    // find the cars that should pass
    for (i = 0; i < vehicles.size(); i++)
    {
        if (vehicles[i]->isReady() && (vehicles[i]->getExitNode() != ent->getNodeNum()))
        {
            cout << "Car: " << i << " is ready!" << endl;
            vehToPass.push_back(vehicles[i]);
            vehicles.erase(vehicles.begin() + i);
        }
    }
    // Selecting random vehicle to stay if the next segment is full
    while (vehToPass.size() > next->capacity)
    {
        cout << "A lot of cars!" << endl;
        i = rand() % vehToPass.size();
        vehToAdd.push_back(vehToPass[i]);
        vehToPass.erase(vehToPass.begin() + i);
    }

    // Adding the chosen cars
    for (Vehicle *veh : vehToAdd)
    {
        vehicles.push_back(veh);
    }

    // Adding cars to the next segment
    next->enter(vehToPass);
    passed = vehToPass.size();
}

void Segment::operate()
{

    // Exit vehicles from the highway
    exit();
    cout << "Vehicles left from the highway!" << endl;

    // let the vehicles in from the previous segment
    if (previous != nullptr)
    {
        previous->pass();
        cout << "Vehicles have passed!" << endl;
    }

    int freeSpace = 0;
    if (capacity > get_no_of_vahicles())
    {
        cout << "Segment has free space!" << endl;
        freeSpace = capacity - get_no_of_vahicles();
        cout << "Free space: " << freeSpace << endl;
        vector<Vehicle *> vehToAdd = ent->operate(freeSpace);
        enter(vehToAdd);
        cout << "Vehicles added" << endl;
    }
    else
    {
        cout << "This segment is full!" << endl;
    }
    entered = freeSpace;

    // preparing the cars for the next round
    int readifyCars = vehicles.size() * percent / 100;
    int randomSelect = rand() % vehicles.size();
    int counterOfReadyCars = getReadyVeh();
    int i = 0;
    while (i < readifyCars && counterOfReadyCars < get_no_of_vahicles())
    {

        if (vehicles[randomSelect]->isReady() == false)
        {
            vehicles[randomSelect]->prepare();
            counterOfReadyCars++;
            i++;
        }
        randomSelect = rand() % vehicles.size();
    }
    cout << "Prepared cars: " << readifyCars << endl;
}

void Segment::setPrevious(Segment *seg)
{
    previous = seg;
    if (seg != nullptr)
        seg->next = this;
    cout << "Next segment set!" << endl;
}

// Returns the number of ready vehicles
int Segment::getReadyVeh()
{
    int ready = 0;
    for (Vehicle *veh : vehicles)
    {
        if (veh->isReady())
            ready++;
    }
    return ready;
}

Segment::~Segment()
{
    if (previous != nullptr)
        previous->next = nullptr;
    if (next != nullptr)
        next->previous = nullptr;

    for (Vehicle *veh : vehicles)
        delete veh;

    cout << "Segment destroyed successfully!" << endl;
}