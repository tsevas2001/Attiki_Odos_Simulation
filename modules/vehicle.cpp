#include "../headers/vehicle.hpp"

Vehicle::Vehicle(int num, string node, Segment segm) : id{num}, exitNode{node}, currentSegm{segm}
{
    indication = -1;
    cout << "Vehicle with ID: " << id << ", Current Node: " << exitNode << ", Current Segment: " << exitNode << " Created Successfully!" << endl;
}

void Vehicle::getInfo()
{
    cout << "Vehicle with ID: " << id << ", Current Node: " << exitNode << ", Current Segment: " << exitNode << endl;
}

// void Vehicle::setInfo(string node, Segment segm) : exitNode{node}, currentSegm{segm}
// {
// }

Vehicle::~Vehicle()
{
    cout << "Vehicle ID: " << id << " destroyed successfully!" << endl;
}