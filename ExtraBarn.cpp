#include "ExtraBarn.h"

ExtraBarn::ExtraBarn(CropField *cropField, int additionalCapacity)
    : CropField(cropField->getCropType(), cropField->getTotalCapacity(), cropField->getUnitID(), cropField->getLocation(), cropField->getEnergyConsumption(), cropField->getYield()), cropField(cropField), additionalCapacity(additionalCapacity) {}

void ExtraBarn::add()
{
    std::cout << "Adding an extra barn with capacity: " << additionalCapacity << std::endl;
    cropField->setTotalCapacity(cropField->getTotalCapacity() + additionalCapacity);
}

int ExtraBarn::getLeftoverCapacity()
{
    return additionalCapacity; 
}

int ExtraBarn::getTotalCapacity()
{
    return cropField->getTotalCapacity() + additionalCapacity;
}

string ExtraBarn::getName()
{
    return "ExtraBarn: " + unitID + " at " + location;
}

int ExtraBarn::getYield()
{
    return cropField->getYield();
}

void ExtraBarn::print()
{
    std::cout<<"EXTRA BARN DETAILS: "<<std::endl;
    std::cout<<"Left over Capacity: "<<getLeftoverCapacity()<<"\t "<<"Total Capacity: "<<getTotalCapacity()<<"\t"<<"Yield: "<<getYield()<<"\t"<<"Affected: "<<getName()<<std::endl;
}