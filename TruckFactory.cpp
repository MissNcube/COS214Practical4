#include "TruckFactory.h"
#include <iostream>

Truck *TruckFactory::createTruck(const std::string &truckType, CropField *field, int threshold, int id, int capy)
{
    if (truckType == "DeliveryTruck")
    {
        return new DeliveryTruck(field, threshold, id, capy);
    }
    else if (truckType == "FertilizerTruck")
    {
        return new FertilizerTruck(field, threshold, id, capy);
    }
    else{
                std::cerr << "TruckFactory: Invalid truck type: " << truckType << std::endl;

    return NULL; }
}
