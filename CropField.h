#ifndef CROP_FIELD_H
#define CROP_FIELD_H

#include "FarmUnit.h"
// #include "SoilState.h"

class CropField : public FarmUnit
{
private:
    string cropType; // Changed from const char* to string for better handling
    int totalCapacity;
    int currentStorage;
    // SoilState* soilState; // Pointer to the current soil state

public:
    CropField(string cropType, int totalCapacity, string unitID, string location, double energyConsumption);

    int getTotalCapacity() override;
    string getCropType() override;
    string getSoilStateName() override;
    string getUnitID() override;
    string getLocation() override;
    double getEnergyConsumption() override;
    double getSensorData(string sensor) const override; // Implementing pure virtual
                                                        // void setSoilState(SoilState* state);
    void harvestCrops();
    // Implementing pure virtual methods from FarmUnit
    void updateSensorData(string sensor, double value) override; // Implementing pure virtual
};

#endif // CROP_FIELD_H
