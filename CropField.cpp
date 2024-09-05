#include "CropField.h"


CropField::CropField(string cropType, int totalCapacity,string unitID, string location, double energyConsumption, int yield):FarmUnit("CropField",unitID, location, energyConsumption)
{           
            this->unitID = unitID;
            this->location = location;
            this->cropType = cropType;
            this->totalCapacity = totalCapacity;
            this->energyConsumption = energyConsumption;
            this->yield = yield;
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

int CropField::getYield()
{
    return this->yield; 
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
    cout << "Harvesting:  " << cropType << " field." << endl;
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

SoilState *CropField::getSoilState()
{
    return soilState;
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

void CropField::setYield(int i)
{
    this->yield = i;
}

void CropField::currSoilState()
{
    if(soilState && soilState->getName() == "Dry")
    {
      notifications->notifyTruck();
      std::cout<<"Trucks were notified of the dry soil."<<std::endl;
    }
}

void CropField::currStorageCap()
{
    if(totalCapacity >= 1000)
    {
        notifications->notifyTruck();
    }else
    {
        std::cout<<"!!!!WORK HARDER!!!!"<<std::endl;
    }
}

void CropField::displayDetails(CropField *field)
{
    std::cout<<"CROPFIELD DATA : "<<std::endl;
    std::cout<<field->getCropType()<<"\t"<<
    field->getLocation()<<"\t"<<
    field->getUnitID()<<"\t"<<
    field->getEnergyConsumption()<<"\t"<<
    field->getYield()<<"\t "<<
    field->getTotalCapacity()<<"\t"<<
    field->getSoilStateName()<<std::endl;
}
