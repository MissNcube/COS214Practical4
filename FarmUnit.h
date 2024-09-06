#ifndef FARMUNIT_H
#define FARMUNIT_H

#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "Truck.h"

using namespace std;

class FarmUnit
{
protected:
    string unitType;
    string unitID;
    string location;
    map<string, double> sensorData;
    double energyConsumption;
    CropField *cropfield;

public:
    FarmUnit(string unitType, string unitID, string location, double energyConsumption);
    virtual ~FarmUnit();

    virtual int getTotalCapacity() = 0;
    virtual string getCropType() = 0;
    virtual string getUnitID() = 0;
    virtual string getLocation() = 0;
    virtual double getSensorData(string sensor) const = 0;
    virtual int getYield() = 0;
    virtual double getEnergyConsumption() = 0;
    virtual void updateSensorData(string sensor, double value) = 0;
    virtual string getName() = 0;
};

#endif
