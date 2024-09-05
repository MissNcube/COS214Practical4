#include "Truck.h"


Truck::Truck(CropField* field, int threshold, int id, int capacity )
{
    this->field = field;
    this->thresH = threshold;
    this->id = id;
    this->capacity = capacity;
    callCounter = 0;

}

int Truck::getCalls() const
{
    return this->callCounter;
}

int Truck::getId() const
{
    return this->id;
}