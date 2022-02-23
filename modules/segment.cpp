#include "../headers/segment.hpp"

Segment::Segment(Entrance* en, int cap, Segment* pre, int id) : ent{en}, capacity{cap}, previous{pre}, next{nullptr}
{
    cout << "Creating segment with ID: " << id << endl;
    percent = 0;

    cout << "Segment opened successfully!" << endl;
}

void Segment::enter(vector<Vehicle*> addVehicles){

    while((vehicles.size() < capacity) && (addVehicles.size() != 0)){

        cout << "Cars where can enter: " << capacity - vehicles.size() << endl;
        cout << "Cars left: " << addVehicles.size() << endl;

        vehicles.push_back(addVehicles[0]); //  adding the car in the array with every car in the highway
        addVehicles[0]->enter(numSeg); // let the car to enter
        addVehicles.erase(addVehicles.begin()); // removes the first car from the array

    }
}

void Segment::exit(){

    for (int i = 0; i < vehicles.size(); i++){
        cout << "Checking car " << i << " to exit..." << endl;

        if((vehicles[i]->isReady()) && (vehicles[i]->getExitNode() == ent->getNode())){
            Vehicle* removeVeh = vehicles[i];
            vehicles.erase(vehicles.begin() + i);
            cout << "Car " << i << " removed from the highway!" << endl;
            i--;
            delete removeVeh;
        }else if (vehicles[i]->getExitNode() == ent->getNode()){
            cout << "Car " << i << " not ready yet to exit!" << endl;
        }else{
            cout << "Car " << i << " will exit at node " << vehicles[i]->getExitNode() << " with ID: "<< ent->getNode() << endl;
        }
    }
}

Segment::~Segment()
{
    if (previous != nullptr)
        previous->next = nullptr;
    if (next != nullptr)
        next->previous = nullptr;

    for (Vehicle* veh : vehicles)
        delete veh;

    cout << "Segment destroyed successfully!" << endl;
}