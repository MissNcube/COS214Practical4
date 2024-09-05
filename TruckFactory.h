#ifndef TRUCKFACTORY_H
#define TRUCKFACTORY_H

#include <string>
#include "Truck.h"
#include "DeliveryTruck.h"
#include "FertilizerTruck.h"


class CropField;

class TruckFactory {
public:
    static Truck* createTruck(const std::string& truckType, CropField* field, int threshold, int id, int capy);
};

#endif
