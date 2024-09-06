#ifndef DELIVERYTRUCK_H
#define DELIVERYTRUCK_H

#include "Truck.h"

class DeliveryTruck : public Truck
{
private:
    int callCounter;

public:
    DeliveryTruck(CropField *field, int threshold, int id, int capacity);
    ~DeliveryTruck();
    void callTruck() override;
    void startEngine() override;
    int getCallCounter() const;
};

#endif
