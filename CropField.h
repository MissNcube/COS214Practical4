#ifndef CROP_FIELD_H
#define CROP_FIELD_H

#include "FarmUnit.h"
// #include "SoilState.h"

class CropField : public FarmUnit
{
private:
    string cropType; 
    int totalCapacity;
    // SoilState* soilState; 

public:
    CropField(string cropType, int totalCapacity, string unitID, string location, double energyConsumption);

    int getTotalCapacity() override;
    string getCropType() override;
   // string getSoilStateName() override;
    string getUnitID() override;
    string getLocation() override;
    double getEnergyConsumption() override;
    double getSensorData(string sensor) const override; 
     // void setSoilState(SoilState* state);
    void harvestCrops();
    void updateSensorData(string sensor, double value) override; 
};

#endif 
