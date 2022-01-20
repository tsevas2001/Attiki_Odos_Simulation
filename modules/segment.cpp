#include "../headers/segment.hpp"

Segment::Segment(Entrance en, vector<Vehicle> veh, int, Segment *nex, Segment *pre, int ind) : ent{en}, vehicles{veh}, next{nex}, previous{pre}, indication{ind}
{
    cout << "Segment opened successfully!" << endl;
}

Segment::~Segment()
{
    cout << "Segment destroyed successfully!" << endl;
}