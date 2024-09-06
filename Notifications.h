#ifndef NOTIFICATIONS_H
#define NOTIFICATIONS_H

#include <vector>
#include <iostream>
#include <string>
#include "Truck.h"

class Notifications
{
protected:
    std::vector<Truck *> trucks;

public:
    virtual ~Notifications() = default;
    virtual void addTruck(Truck *truck) = 0;
    virtual void removeTruck(Truck *truck) = 0;
    virtual void notifyTrucks() = 0;
    virtual void notifyTruck(Truck *specificTruck) = 0;
    virtual size_t getCount() const = 0;
};

#endif
