#include "FertilizerTruck.h"
#include "SoilState.h"
#include "FruitfulSoil.h"


FertilizerTruck::FertilizerTruck(CropField *field, int threshold,int id,int cap  ) : Truck(field,threshold,id,capacity)
{
    this->field = field;
    this->id  = id;
}

FertilizerTruck::~FertilizerTruck()
{
}

void FertilizerTruck::callTruck()
{
    std::cout << "CALLED THE TRUCK FOR FERTILIZATION" << std::endl;
    startEngine();
}

void FertilizerTruck::startEngine()
{
    std::cout << "STARTED THE ENGINE" << std::endl;
    //need to change the state to fruitful if it is dry 
    if (field->getSoilStateName()=="Dry")
    {
        //change to fruitful
        field->setSoilState(new FruitfulSoil());
    }
}

int FertilizerTruck::getId()
{
    return this->id;
}

// std::string FertilizerTruck::getType() const
// {
//     return "FertilizerTruck";
// }
