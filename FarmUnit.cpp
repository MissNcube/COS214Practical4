#include "FarmUnit.h"
#include "TruckFactory.h"
#include "Truck.h"
#include "CompositeFarm.h"

FarmUnit::FarmUnit(string unitType, string unitID, string location, double energyConsumption)
{
    this->unitType = unitType;
    this->unitID = unitID;
    this->location = location;
    this->notifications = new Notifications(); // Initialize notifications system
}

FarmUnit::~FarmUnit()
{
    delete notifications;
}

Truck* FarmUnit::buyTruck(const std::string &truckType, CropField *field, int threshold, int id, int capacity)
{
    Truck *newTruck = TruckFactory::createTruck(truckType, field, threshold, id, capacity);
    if (newTruck)
    {
        auto compositeFarm = dynamic_cast<CompositeFarm*>(this);
        if (compositeFarm)
        {
            compositeFarm->addTruck(newTruck);  // Add truck to CompositeFarm
            std::cout << "Truck added to CompositeFarm. Current truck count: " 
                      << compositeFarm->getTruckCount() << std::endl; 
        }
             notifications->addTruck(newTruck);  // Add truck to notification list
        std::cout << "Truck bought: " << truckType << " for field " << field->getUnitID() << std::endl;
        }
   
    else
    {
        std::cout << "Invalid truck type: " << truckType << std::endl;
    }
    return newTruck;

}

void FarmUnit::sellTruck(Truck *truck)
{
    if (!truck) {
        std::cout << "Invalid truck. Cannot sell." << std::endl;
        return;
    }
    // If part of CompositeFarm, remove truck from CompositeFarm
    if (auto compositeFarm = dynamic_cast<CompositeFarm*>(this))
    {
        compositeFarm->removeTruck(truck);  // Remove truck from the CompositeFarm list
    }

    // Remove truck from the notification system
    notifications->removeTruck(truck);  

    // Clean up the truck resource
    delete truck;
    
    std::cout << "Truck sold successfully!" << std::endl;
}


