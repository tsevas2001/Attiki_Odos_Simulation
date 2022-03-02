/* HERE ARE EXTRA FUNCTIONS FOR THE DEVELOPMENT OF PROJECT */
#include "../main.hpp"
#include "vehicle.hpp"

string randStr() // return random string of 10 characters for author and title of book
{
    int MAX = 26;
    int length = 10; // the length of string
    char alphabet[MAX] = {'a', 'b', 'c', 'd', 'e', 'f', 'g',
                          'h', 'i', 'j', 'k', 'l', 'm', 'n',
                          'o', 'p', 'q', 'r', 's', 't', 'u',
                          'v', 'w', 'x', 'y', 'z'};
    string result = "";
    for (int i = 0; i < length; i++) // return random string with 10 characters
        result = result + alphabet[rand() % MAX];

    return result;
}

int randNum(int min, int max) // return random integer number between min and max
{
    return (rand() % max + min);
}
