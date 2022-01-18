#include "main.hpp"
#include "highway.hpp"

using namespace std;

class Segment : public Highway
{
private:
    Entrance ent;
    vector<Vehicle> vehicles;
    int capacity;
    Segment next;
    Segment previous;
    int indication;

public:
    Segment();
    void enter();
    void exit();
    void pass();
    int get_no_of_vahicles();
    ~Segment();
};