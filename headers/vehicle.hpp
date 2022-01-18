#include "main.hpp"
#include "segment.hpp"

using namespace std;

class Vehicle
{
private:
    int id;
    int indication;
    Node currentNode;
    Segment currentSegm;

public:
    Vehicle(int, Node, Segment);
    void getInfo();
    void setInfo(Node, Segment);
    ~Vehicle();
};