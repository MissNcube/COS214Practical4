#ifndef CROP_FIELD_H
#define CROP_FIELD_H

#include "FarmUnit.h"
#include "Notifications.h"

#include "Truck.h"

#include "SoilState.h"
#include "DrySoil.h"

#include <iostream>
#include <vector>
#include <algorithm>

class CropField : public FarmUnit, public Notifications
{
private:
    std::string cropType;
    int totalCapacity;
    SoilState *soilState;
    int yield;
    std::vector<Truck *> trucks;

public:
    //
    CropField(std::string cropType, int totalCapacity, std::string unitID, std::string location, double energyConsumption, int yield);    
    int getTotalCapacity() override;
    std::string getCropType() override;
    std::string getUnitID() override;
    std::string getLocation() override;
    double getEnergyConsumption() override;
    int getYield() override;
    void updateSensorData(std::string sensor, double value) override;
    double getSensorData(std::string sensor) const override;
    //
    void retrieveCrops();
    void setSoilState(SoilState *state);
    std::string getSoilStateName();
    SoilState *getSoilState();
    void rain(CropField *field, double rainAmt);
    int harvestCrops(CropField *crop);
    void setTotalCapacity(int capacity);
    void setYield(int i);
    void currSoilState();
    void currStorageCap();
    void displayDetails();
    std::string getName() override;
    //
    void addTruck(Truck *truck) override;
    void removeTruck(Truck *truck) override;
    void notifyTrucks() override;
    void notifyTruck(Truck *specificTruck) override;
    size_t getCount() const override;
    //
    Truck *buyTruck(const std::string &truckType, int threshold, int id, int capacity);
    void sellTruck();
};

#endif
