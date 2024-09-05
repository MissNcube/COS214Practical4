#include "ExtraBarn.h"

ExtraBarn::ExtraBarn(CropField *cropField, int additionalCapacity)
    : CropField(cropField->getCropType(), cropField->getTotalCapacity(), cropField->getUnitID(), cropField->getLocation(), cropField->getEnergyConsumption(),cropField->getYield()), cropField(cropField), additionalCapacity(additionalCapacity) {}

void ExtraBarn::add()
{
            // Logic to enhance storage capacity
        std::cout << "Adding an extra barn with capacity: " << additionalCapacity << std::endl;
        cropField->setTotalCapacity(cropField->getTotalCapacity() + additionalCapacity);
}
int ExtraBarn::getLeftoverCapacity()
{
   return cropField->getTotalCapacity();
}

string ExtraBarn::getName()
{
    return "ExtraBarn: " + unitID + " at " + location;
}
