#include "main.h"
#include "headers/highway.h"

int main(int argc, char *argv[])
{
    srand(time(NULL));

    if (argc != 5)
    {
        cout << "Wrong amount of arguments!\n";
        return 1;
    }

    // convert argumnets to integers
    int n = atoi(argv[1]);       // amount of cycles operation
    int nSegs = atoi(argv[2]);   // amount of segments of highway
    int k = atoi(argv[3]);       // max amount of vehicles in a segment
    int percent = atoi(argv[4]); // percent per segment

    Highway *highway = new Highway(nSegs, percent, k);

    for (int i = 0; i < n; i++)
        highway->operate();

    delete highway;

    return 0;
}
