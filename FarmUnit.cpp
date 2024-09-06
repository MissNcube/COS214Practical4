#include "FarmUnit.h"
#include "TruckFactory.h"
#include "Truck.h"
#include "CompositeFarm.h"

FarmUnit::FarmUnit(string unitType, string unitID, string location, double energyConsumption)
{
    this->unitType = unitType;
    this->unitID = unitID;
    this->location = location;
}

FarmUnit::~FarmUnit()
{
}
