#ifndef NOTIFICATION_H
#define NOTIFICATIONS_H

#include <iostream>
#include <vector>


#include "Truck.h"
class Truck;

class Notifications
{
    private:
    std::vector<Truck*> obs;

    public:
    virtual ~Notifications();
    void addTruck(Truck* trk);
    void removeTruck(Truck* trk);
    void notifyTruck();
    size_t getCount() const;

};

#endif