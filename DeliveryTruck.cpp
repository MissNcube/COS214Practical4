#include "DeliveryTruck.h"
#include "CropField.h"

DeliveryTruck::DeliveryTruck(CropField *field, int threshold, int id, int cap) : Truck(field, threshold, id, capacity)
{
    this->field = field;
    this->id = id;
}

DeliveryTruck::~DeliveryTruck() {}

void DeliveryTruck::callTruck()
{
    std::cout << "\t -" << "CALLED THE DELIVERY TRUCK" << std::endl;
    callCounter++;
    startEngine();
}

void DeliveryTruck::startEngine()
{
    std::cout << "STARTING ENGINE" << std::endl;
    int yield = field->getYield();

    if (yield >= 100)
    {
        yield -= 100;
        field->setYield(yield);
        std::cout << "*CROPS COLLECTED!*" << std::endl;
    }
    else
    {
        std::cout << "NOT ENOUGH CROPS TO COLLECT WORK HARDER" << std::endl;
    }
}

int DeliveryTruck::getCallCounter() const
{
    return callCounter;
}
