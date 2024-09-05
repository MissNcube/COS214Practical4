#include "CompositeFarm.h"
#include "Truck.h"

#include <algorithm>

CompositeFarm::CompositeFarm(string unitID, string location, double energyConsumption)
    : FarmUnit("CompositeFarm", unitID, location, energyConsumption) {}

CompositeFarm::~CompositeFarm() 
{
    for (FarmUnit* unit : units) {
        delete unit;
    }
    units.clear();

    for(Truck* truck : trucks)
    {
        delete truck;
    }
    trucks.clear();
}

int CompositeFarm::getTotalCapacity()
{
    int total = 0;
    for (const auto& unit : units) {
        total += unit->getTotalCapacity();
    }
    return total;
}


string CompositeFarm::getCropType() 
{
     std::string crops;
        for (auto unit : units) {
            if (!crops.empty()) {
                crops += "| ";
            }
            crops += unit->getCropType();
        }
        return crops;
}


double CompositeFarm::getEnergyConsumption() 
{
    double tltE = this->energyConsumption;
    for (const auto& unit : units) {
        tltE += unit->getEnergyConsumption();
    }
    return tltE;
}

double CompositeFarm::getSensorData(string sensor) const 
{
    double sum = 0;
    int sensors = 0;

    for (const auto& unit : units) {
        double val = unit->getSensorData(sensor);
        if (val != -1) {
            sum += val;
            sensors++;
        }
    }

    return sensors > 0 ? sum / sensors : -1;
}

int CompositeFarm::getYield()
{
       int tlt = 0;
    for (const auto& unit : units) {
        tlt += unit->getYield();
    }
    return tlt;
    
}

string CompositeFarm::getUnitID() 
{
   std::string combinedUnitIDs;
        for (auto unit : units) {
            if (!combinedUnitIDs.empty()) {
                combinedUnitIDs += "| ";
            }
            combinedUnitIDs += unit->getUnitID();
        }
        return combinedUnitIDs;
}

string CompositeFarm::getLocation() 
{
    std::string combinedLocations;
        for (auto unit : units) {
            if (!combinedLocations.empty()) {
                combinedLocations += "| ";
            }
            combinedLocations += unit->getLocation();
        }
        return combinedLocations;
}

void CompositeFarm::updateSensorData(string sensor, double value) 
{
    for (auto& unit : units) {
        unit->updateSensorData(sensor, value);
    }
}

void CompositeFarm::addUnit(FarmUnit* unit)
{
    if(unit)
    {
        units.push_back(unit);
        
    }
    else
    {
        return;
    }
}

void CompositeFarm::removeUnit(FarmUnit* unit) 
{
    if(unit){
        units.erase(remove(units.begin(), units.end(), unit), units.end());
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
