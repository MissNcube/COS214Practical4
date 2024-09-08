#ifndef FERTILIZERTRUCK_H
#define FERTILIZERTRUCK_H

#include "Truck.h"

class FertilizerTruck : public Truck
{

    
public:
    FertilizerTruck(CropField* field, int threshold, int id, int capacity);
    ~FertilizerTruck();
    void callTruck() override;
    void startEngine() override;
};

#endif
