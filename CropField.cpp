#include "CropField.h"

CropField::CropField(string cropType, int totalCapacity, string unitID, string location, double energyConsumption):FarmUnit("CropField",unitID, location, energyConsumption)
{
            this->cropType = cropType;
            this->totalCapacity = totalCapacity;
            this->energyConsumption = energyConsumption;
}

int CropField::getTotalCapacity()
{
    return this->totalCapacity;
}

string CropField::getCropType()
{
    return this->cropType;
}

string CropField::getUnitID()
{
    return this->unitID;
}

string CropField::getLocation()
{
    return this->location;
}

void CropField::updateSensorData(string sensor, double value)
{
     sensorData[sensor] = value;
}

double CropField::getSensorData(string sensor) const
{
     auto it = sensorData.find(sensor);
    return (it != sensorData.end()) ? it->second : -1; // Return -1 if sensor not found
}

double CropField::getEnergyConsumption()
{
    return this->energyConsumption;
}

void CropField::harvestCrops()
{
    cout << "Harvesting crops from " << cropType << " field." << endl;
}
