#include "DeliveryTruck.h"

#include <iostream>

DeliveryTruck::DeliveryTruck(CropField *field,int threshold,int id,int cap):Truck(field,threshold,id,capacity)
{
    this->field = field;
    this->id = id;
    called = 0;

}

DeliveryTruck::~DeliveryTruck()
{
    
}

void DeliveryTruck::callTruck()
{
    std::cout<<"CALLED THE DELIVERY TRUCK"<<std::endl;
    called++;
    startEngine();
}


void DeliveryTruck::startEngine()
{
    std::cout<<"STARTING ENGINE"<<std::endl;
    //go collect the crops
    int yield = field->getYield();
    if(yield >= 100)
    {
    yield -= 100;
    field->setYield(yield);
    std::cout<<"CROPS COLLECTED!"<<std::endl;
    }
    else
    {
        std::cout<<"NOT ENOUGH CROPS TO COLLECT"<<std::endl;
    }

}

int DeliveryTruck::getId()
{
    return this->id ;
}

int DeliveryTruck::getCallCounter()
{
    return this->called;
}
// std::string DeliveryTruck::getType() const
// {
//     return "DeliveryTruck";
// }
