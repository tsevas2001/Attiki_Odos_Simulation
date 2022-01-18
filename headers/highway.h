#include <iostream>

using namespace std;

class Highway {
    int N_Segs;
    int total_vehicles;
    int space;

    Highway();
    void enter();
    void exit();
    void pass();
    int get_no_of_vehicles();
    ~Highway();
};