#include "../headers/highway.hpp"

Highway::Highway(int maxVeh, vector<Segment> seg) : totalVehicles{maxVeh}, nSegs{seg}
{
    cout << "Highway opened successfully!" << endl;
}

void Highway::operate()
{
    
}

Highway::~Highway()
{
    cout << "Highway destroyed successfully!" << endl;
}