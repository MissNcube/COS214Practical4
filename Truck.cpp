#include "Truck.h"
#include "CropField.h"

Truck::Truck(CropField *field, int threshold, int id, int capacity)
{
    this->field = field;
    this->threshold = threshold;
    this->id = id;
    this->capacity = capacity;
    callCounter = 0;
}

int Truck::getId() const
{
    return this->id;
}

int Truck::getThreshold() const
{
    return this->threshold;
}

int Truck::getCapacity() const
{
    return this->capacity;
}

int Truck::getCallCounter() const
{
    return callCounter;
}
