#ifndef SOILSTATE_H
#define SOILSTATE_H
#include <iostream>
using namespace std;

class SoilState
{
    private:
        string name;
    public :
        void harvestCrops();
        void rain();
        string getName();
};

#endif //SOILSTATE_H