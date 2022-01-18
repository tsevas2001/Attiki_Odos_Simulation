#include "main.hpp"
#include "highway.hpp"

class Node : public Highway
{
private:
    string nodeName;

public:
    Node();
    ~Node();
};