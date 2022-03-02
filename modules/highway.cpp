#include "../headers/highway.hpp"

Highway::Highway()
{
    int carCapacity, manNum, unNum;
    vector<Segment*> addSegs;
    nSegs = 0;
    Segment* prevSeg = nullptr;

    for (int i = 0; i < nSegs; i++){
        cout << "Enter capacity: " << i;
        cin >>  carCapacity;

        manNum = rand() % 8 + 1;
        unNum = rand() % 8 + 1;

        addSegs.push_back(new Segment(new Entrance(i, manNum, unNum), carCapacity, prevSeg, i, nSegs));
        
        prevSeg = addSegs[i];
        segments.push_back(addSegs[i]);
    }
    cout << "Highway opened successfully!" << endl;
}

void Highway::operate()
{
    for (int i = segments.size() - 1; i >= 0; i--){
        cout << "Segment " << i << endl;
        segments[i]->operate();
    }
    cout << "Highway operation completed successfully!" << endl;
}

void Highway::set(int total){
    nSegs = total;
}

void Highway::print(){
    int i = 0;

    for (Segment* seg : segments) {
        cout << "Segment id:" << i << endl;
        i++;
    }
}

Highway::~Highway()
{
    for(Segment* seg : segments){
        delete seg;
    }
    cout << "Highway destroyed successfully!" << endl;
}