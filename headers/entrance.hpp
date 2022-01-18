#include "main.hpp"
#include "segment.hpp"

using namespace std;

class Entrance : public Segment
{
private:
    String nodeName;
    vector<Tool> collectorTool;
    vector<Tool> eTool;
    int capacity;

public:
    Entrance();
    ~Entrance();
    virtual void removeVehicle() = 0; // pure virtual
};