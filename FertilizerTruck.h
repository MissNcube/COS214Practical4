#ifndef FERTILIZERTRUCK_H
#define FERTILIZERTRUCK_H


#include "Truck.h"
#include "CropField.h"
#include <iostream>
#include <string>


class FertilizerTruck : public Truck
{
    private:
    CropField* field;
    Truck* counter;
    int id;

    public:
    FertilizerTruck(CropField* field, int threshold, int id,int cap);
    ~FertilizerTruck();
    void callTruck() override;
    void startEngine() override;
    int getId();
    // std::string getType() const override;
    
};

#endif