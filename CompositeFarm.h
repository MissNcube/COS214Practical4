#ifndef COMPOSITE_FARM_H
#define COMPOSITE_FARM_H

#include "FarmUnit.h"
#include <vector>

class CompositeFarm : public FarmUnit {
private:
    vector<FarmUnit*> farmUnits; // Collection of farm units (CropFields, Barns, etc.)

public:
   CompositeFarm(string unitID, string location, double energyConsumption);
    ~CompositeFarm();

    // Implementing the required virtual methods
    int getTotalCapacity() override; // Aggregate capacity from all child units
    string getCropType() override; // Return crop type based on child units
    string getSoilStateName() override; // Return soil state name based on child units
    double getEnergyConsumption() override; // Aggregate energy consumption from all child units
    string getUnitID() override;
    string getLocation() override;  
    double getSensorData(string sensor) const override;
    void updateSensorData(string sensor, double value) override;
    // Methods to manage farm units
    void addUnit(FarmUnit* unit);
    void removeUnit(FarmUnit* unit);
    vector<FarmUnit*> getFarmUnits() const; // Get all farm units
};

#endif // COMPOSITE_FARM_H
