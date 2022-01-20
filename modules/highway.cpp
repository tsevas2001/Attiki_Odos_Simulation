#include "../headers/highway.hpp"

Highway::Highway(int maxVeh, vector<Segment> seg) : totalVehicles{maxVeh}, nSegs{seg}
{
    cout << "Highway opened successfully!" << endl;
}

Highway::~Highway()
{
    cout << "Highway destroyed successfully!" << endl;
}