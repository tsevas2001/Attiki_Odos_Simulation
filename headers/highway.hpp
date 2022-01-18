#include "main.hpp"
#include "segment.hpp"

using namespace std;

class Highway
{
private:
    vector<Segment> nSegs;
    int totalVehicles;

public:
    Highway();
    void operate();
    void enter();
    void exit();
    void pass();
    int get_no_of_vehicles();
    ~Highway();
};