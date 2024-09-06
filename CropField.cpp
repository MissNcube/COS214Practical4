#include "CropField.h"
#include "TruckFactory.h"

CropField::CropField(string cropType, int totalCapacity, string unitID, string location, double energyConsumption, int yield) : FarmUnit("CropField", unitID, location, energyConsumption)
{
    this->unitID = unitID;
    this->location = location;
    this->cropType = cropType;
    this->totalCapacity = totalCapacity;
    this->energyConsumption = energyConsumption;
    this->yield = yield;
    this->soilState = new DrySoil();
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
    if (soilState)
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

void CropField::rain(CropField *field, double rainAmt)
{
    soilState->rain(field, rainAmt);
}

int CropField::harvestCrops(CropField *crop)
{
    std::cout << "Harvesting crops based on current soil state." << std::endl;
    int yield = soilState->harvestCrops(crop);
    return yield;
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
    if (soilState && soilState->getName() == "Dry")
    {
        notifyTrucks();
        std::cout << "Notified the trucks about the DrySoil" << std::endl;
    }
}

void CropField::currStorageCap()
{
    if (totalCapacity >= 1000)
    {
        notifyTrucks();
    }
    else
    {
        std::cout << "!!!!WORK HARDER!!!!" << std::endl;
    }
}

void CropField::displayDetails()
{
    std::cout << "CropField: " << cropType << "\t" << location << "\t" << unitID << "\t" << energyConsumption << "\t" << yield << "\t " << totalCapacity << "\t" << getSoilStateName() << std::endl;
}

string CropField::getName()
{
    return "CropField: " + cropType + " at " + location;
}

// notifications overrides
void CropField::addTruck(Truck *trk)
{
    trucks.push_back(trk);
    std::cout << "TRUCK ADDED TO: " << cropType << std::endl;
}

void CropField::removeTruck(Truck *trk)
{
    trucks.erase(std::remove(trucks.begin(), trucks.end(), trk), trucks.end());
    std::cout << "TRUCK REMOVED FROM : " << cropType << std::endl;
}

void CropField::notifyTrucks()
{
    for (Truck *truck : trucks)
    {
        truck->callTruck();
    }
}

void CropField::notifyTruck(Truck *specificTruck)
{
    auto it = std::find(trucks.begin(), trucks.end(), specificTruck);
    if (it != trucks.end())
    {
        specificTruck->callTruck();
    }
    else
    {
        std::cout << "! TRUCK NOT IN NOTIFICATIONS !" << std::endl;
    }
}

size_t CropField::getCount() const
{
    return trucks.size();
}

Truck *CropField::buyTruck(const std::string &truckType, int threshold, int id, int capacity)
{
    Truck *boughTruck = TruckFactory::createTruck(truckType, this, threshold, id, capacity);
    if (boughTruck)
    {
        addTruck(boughTruck);

        std::cout << truckType << " with ID " << id << " has been purchased for field: " << getCropType() << std::endl;
        return boughTruck;
    }
    else
    {
        std::cout << " !TRUCK TYPE INVALID/FAILED TO CREATE TRUCK! " << truckType << std::endl;
    }
}

void CropField::sellTruck()
{
    Truck *sellT = NULL;
    for (auto &truck : trucks)
    {
        DeliveryTruck *delTruck = dynamic_cast<DeliveryTruck *>(truck);
        FertilizerTruck *ferTruck = dynamic_cast<FertilizerTruck *>(truck);

        if (delTruck && delTruck->getCallCounter() == 0)
        {
            sellT = delTruck;
            break;
        }

        if (ferTruck && ferTruck->getCallCounter() == 0)
        {
            sellT = ferTruck;
            break;
        }
    }

    if (sellT)
    {
        removeTruck(sellT);
        std::cout << "Truck with ID " << sellT->getId() << " has been sold." << std::endl;
        delete sellT;
    }
    else
    {
        std::cout << "~NO UNUSED TRUCKS 'YEY'~" << std::endl;
    }
}