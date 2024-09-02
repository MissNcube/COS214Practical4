#include "CompositeFarm.h"
#include <iostream>
#include <algorithm>

CompositeFarm::CompositeFarm(string unitID, string location, double energyConsumption) : FarmUnit("CompositeFarm", unitID, location, energyConsumption)
{
    // Initialize the farm unit's energy consumption
    this->energyConsumption = energyConsumption;
}


CompositeFarm::~CompositeFarm()
{
    for (FarmUnit *unit : farmUnits)
    {
        delete unit; // Clean up memory
    }
}

int CompositeFarm::getTotalCapacity()
{
    int total = 0;
    for (const auto &unit : farmUnits)
    {
        total += unit->getTotalCapacity(); // Aggregate capacity
    }
    return total;
}

string CompositeFarm::getCropType()
{
    // Return crop type based on the first crop field for simplicity
    for (const auto &unit : farmUnits)
    {
        if (unit->getCropType() != "")
        {
            return unit->getCropType();
        }
    }
    return "No crops found"; // Fallback
}

string CompositeFarm::getSoilStateName()
{
    // Return soil state name based on the first crop field for simplicity
    for (const  auto &unit : farmUnits)
    {
        if (unit->getSoilStateName() != "")
        {
            return unit->getSoilStateName();
        }
    }
    return "No soil state found"; // Fallback
}

double CompositeFarm::getSensorData(string sensor) const
{
     auto it = sensorData.find(sensor);
    return (it != sensorData.end()) ? it->second : -1; // Return -1 if sensor not found
}



string CompositeFarm::getUnitID()
{
    return this->unitID;
}

string CompositeFarm::getLocation()
{
    return this->location;
}


void CompositeFarm::updateSensorData(string sensor, double value)
{
     sensorData[sensor] = value;
}




void CompositeFarm::addUnit(FarmUnit *unit)
{
    farmUnits.push_back(unit);
}

void CompositeFarm::removeUnit(FarmUnit *unit)
{
    auto it =std::find(farmUnits.begin(), farmUnits.end(), unit);

    if (it != farmUnits.end())
    {
        farmUnits.erase(it);
    }
}

vector<FarmUnit *> CompositeFarm::getFarmUnits() const
{
    return farmUnits;
}
