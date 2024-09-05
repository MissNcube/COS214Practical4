#ifndef CROP_FIELD_H
#define CROP_FIELD_H


#include "FarmUnit.h"
#include "DrySoil.h"
#include "Notifications.h"


class CropField : public FarmUnit , public Notifications
{
private:
    string cropType; 
    int totalCapacity;
    SoilState* soilState; 
    int yield;

public:
    CropField(string cropType, int totalCapacity,string unitID, string location, double energyConsumption, int yield);

  
    int getTotalCapacity() override;
    string getCropType() override;
    string getUnitID() override;
    string getLocation() override;
    int getYield() override;
    double getEnergyConsumption() override;
    double getSensorData(string sensor) const override; 
    void retrieveCrops();
    void updateSensorData(string sensor, double value) override;

    //State

    void setSoilState(SoilState* state);
    string getSoilStateName(); 
    SoilState* getSoilState();
    void rain(CropField* field, double rainAmt);
    int harvestCrops(CropField* crop) ;
    void setTotalCapacity(int capacity);
    void setYield(int i);

    //truck
    void currSoilState();
    void currStorageCap();
    void displayDetails(CropField* field);

};

#endif 
