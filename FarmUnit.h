#ifndef FARMUNIT_H
#define FARMUNIT_H

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class FarmUnit {
protected:
    string unitType;
    string unitID;
    string location;
    map<string, double> sensorData; 
    double energyConsumption; 

public:
    FarmUnit(string unitType, string unitID, string location, double energyConsumption);
    virtual ~FarmUnit();

    virtual int getTotalCapacity() = 0;
    virtual string getCropType() = 0;
   // virtual string getSoilStateName() = 0;
    virtual string getUnitID()  = 0;
    virtual string getLocation() = 0;
    virtual  double getSensorData(string sensor) const =0;
    virtual int getYield() = 0;
    virtual double getEnergyConsumption() = 0;
    // Pure virtual methods for sensor data management
    virtual void updateSensorData(string sensor, double value) = 0; 

};

#endif 
