#include "FertilizerTruck.h"
#include "FruitfulSoil.h"

FertilizerTruck::FertilizerTruck(CropField *field, int threshold, int id, int cap) : Truck(field, threshold, id, capacity)
{
    this->field = field;
    this->id = id;
    this->capacity = cap;
}

FertilizerTruck::~FertilizerTruck()
{
}

void FertilizerTruck::callTruck()
{
    std::cout << "CALLED THE TRUCK FOR FERTILIZATION" << std::endl;
    callCounter++;
    startEngine();
}

void FertilizerTruck::startEngine()
{
    std::cout << "STARTED THE ENGINE" << std::endl;
    if (field->getSoilStateName() == "Dry")
    {
        field->setSoilState(new FruitfulSoil());
    }
}
