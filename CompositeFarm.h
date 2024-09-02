#ifndef COMPOSITE_FARM_H
#define COMPOSITE_FARM_H

#include "FarmUnit.h"
#include <vector>

class CompositeFarm : public FarmUnit {
private:
    vector<FarmUnit*> farmUnits; 

public:
   CompositeFarm(string unitID, string location, double energyConsumption);
    ~CompositeFarm();

    
    int getTotalCapacity() override; 
    string getCropType() override; 
    //string getSoilStateName() override; // Return soil state name based on child units
    double getEnergyConsumption() override; 
    string getUnitID() override;
    string getLocation() override;  
    double getSensorData(string sensor) const override;
    void updateSensorData(string sensor, double value) override;
    void addUnit(FarmUnit* unit);
    void removeUnit(FarmUnit* unit);
    vector<FarmUnit*> getFarmUnits() const;
};

#endif 
