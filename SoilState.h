#ifndef SOILSTATE_H
#define SOILSTATE_H
#include <iostream>
using namespace std;

class CropField;

class SoilState
{
    private:
        string name;
    public :
        virtual ~SoilState() = default;
        virtual int harvestCrops(CropField* crop) = 0;
        virtual void rain(CropField* field, double rainAmt) = 0 ;
        virtual string getName() const = 0;
        
};

#endif //SOILSTATE_H