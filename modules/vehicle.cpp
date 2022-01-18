#include "../headers/vehicle.hpp"

Vehicle::Vehicle(int num, Node node, Segment segm) : id{num}, currentNode{node}, currentSegm{segm}
{
    indication = -1;
    cout << "Vehicle with ID: " << id << ", Current Node: " << currentNode << ", Current Segment: " << currentSegn << " Created Successfully!" << endl;
}

void Vehicle::getInfo()
{
    cout << "Vehicle with ID: " << id << ", Current Node: " << currentNode << ", Current Segment: " << currentSegn << endl;
}

void Vehicle::setInfo(Node node, Segment segm) : currentNode{node}, currentSegm{segm} {}

Vehicle::~Vehicle()
{
    cout << "Vehicle ID: " << id << " destroyed successfully!" << endl;
}