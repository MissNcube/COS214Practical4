#include "CropField.h"
#include "DrySoil.h"

CropField::CropField(string cropType, int totalCapacity, string unitID, string location, double energyConsumption):FarmUnit("CropField",unitID, location, energyConsumption)
{           
            this->unitID = unitID;
            this->location = location;
            this->cropType = cropType;
            this->totalCapacity = totalCapacity;
            this->energyConsumption = energyConsumption;
            this->soilState = new DrySoil();    //default state
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
    return (it != sensorData.end()) ? it->second : -1; 
}

double CropField::getEnergyConsumption()
{
    return this->energyConsumption;
}

void CropField::retrieveCrops()
{
    cout << "Harvesting crops from " << cropType << " field." << endl;
}

void CropField::setSoilState(SoilState *state)
{
    if(soilState)
    {
        delete soilState;
    }
    this->soilState = state;
}

string CropField::getSoilStateName()
{
    return soilState->getName();
}

void CropField::rain(CropField* field, double rainAmt)
{
    soilState->rain(field, rainAmt);
}

int CropField::harvestCrops(CropField* crop)
{
    std::cout << "Harvesting crops based on current soil state." << std::endl;
    int yield = soilState->harvestCrops(crop);
    //std::cout << "Yield: " << yield << " units of crops harvested." << std::endl;
    return  yield;
}

void CropField::setTotalCapacity(int capacity)
{
    this->totalCapacity = capacity;
}
