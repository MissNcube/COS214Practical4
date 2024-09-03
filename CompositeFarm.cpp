#include "CompositeFarm.h"
#include <algorithm>

CompositeFarm::CompositeFarm(string unitID, string location, double energyConsumption)
    : FarmUnit("CompositeFarm", unitID, location, energyConsumption) {}

CompositeFarm::~CompositeFarm() 
{
    for (FarmUnit* unit : farmUnits) {
        delete unit;
    }
    farmUnits.clear();
}

int CompositeFarm::getTotalCapacity()
{
    int total = 0;
    for (const auto& unit : farmUnits) {
        total += unit->getTotalCapacity();
    }
    return total;
}

string CompositeFarm::getCropType() 
{
     std::string combinedCropTypes;
        for (auto unit : farmUnits) {
            if (!combinedCropTypes.empty()) {
                combinedCropTypes += ", ";
            }
            combinedCropTypes += unit->getCropType();
        }
        return combinedCropTypes;
}

// string CompositeFarm::getSoilStateName() {
//     for (const auto& unit : farmUnits) {
//         string soilState = unit->getSoilStateName();
//         if (!soilState.empty()) {
//             return soilState;
//         }
//     }
//     return "No soil state found";
// }

double CompositeFarm::getEnergyConsumption() 
{
    double totalEnergy = this->energyConsumption;
    for (const auto& unit : farmUnits) {
        totalEnergy += unit->getEnergyConsumption();
    }
    return totalEnergy;
}

double CompositeFarm::getSensorData(string sensor) const 
{
    double totalValue = 0;
    int sensorCount = 0;

    for (const auto& unit : farmUnits) {
        double sensorValue = unit->getSensorData(sensor);
        if (sensorValue != -1) {
            totalValue += sensorValue;
            sensorCount++;
        }
    }

    return sensorCount > 0 ? totalValue / sensorCount : -1;
}

int CompositeFarm::getYield()
{
       int total = 0;
    for (const auto& unit : farmUnits) {
        total += unit->getYield();
    }
    return total;
    
}

string CompositeFarm::getUnitID() 
{
   std::string combinedUnitIDs;
        for (auto unit : farmUnits) {
            if (!combinedUnitIDs.empty()) {
                combinedUnitIDs += ", ";
            }
            combinedUnitIDs += unit->getUnitID();
        }
        return combinedUnitIDs;
}

string CompositeFarm::getLocation() 
{
    std::string combinedLocations;
        for (auto unit : farmUnits) {
            if (!combinedLocations.empty()) {
                combinedLocations += ", ";
            }
            combinedLocations += unit->getLocation();
        }
        return combinedLocations;
}

void CompositeFarm::updateSensorData(string sensor, double value) 
{
    for (auto& unit : farmUnits) {
        unit->updateSensorData(sensor, value);
    }
}

void CompositeFarm::addUnit(FarmUnit* unit)
{
    if(unit)
    {
        farmUnits.push_back(unit);
    }
    else
    {
        return;
    }
}

void CompositeFarm::removeUnit(FarmUnit* unit) 
{
    if(unit){
        farmUnits.erase(remove(farmUnits.begin(), farmUnits.end(), unit), farmUnits.end());
    }
    else 
    {
        return;
    }
}

vector<FarmUnit*> CompositeFarm::getFarmUnits() const 
{
    return farmUnits;
}
