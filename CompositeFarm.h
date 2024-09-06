#ifndef COMPOSITE_FARM_H
#define COMPOSITE_FARM_H

#include "FarmUnit.h"
#include "CropField.h"
#include "Truck.h"
#include <vector>

class CompositeFarm : public FarmUnit
{
private:
    vector<FarmUnit *> units;
    std::vector<Truck *> trucks;
    std::vector<CropField *> fields;

public:
    CompositeFarm(string unitID, string location, double energyConsumption);
    ~CompositeFarm();
    void displayD();
    int getTotalCapacity() override;
    string getCropType() override;
    double getEnergyConsumption() override;
    string getUnitID() override;
    string getLocation() override;
    double getSensorData(string sensor) const override;
    int getYield() override;
    void updateSensorData(string sensor, double value) override;

    // special consideration
    void addUnit(FarmUnit *unit);
    void removeUnit(FarmUnit *unit);
    vector<FarmUnit *> getFarmUnits() const;
    string getName() override;

    // TRUCK SITUATION:
    void addTruck(Truck *truck);
    void removeTruck(Truck *truck);
    int getTruckCount() const; 
};

#endif
