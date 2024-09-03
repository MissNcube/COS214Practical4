#include "Fertilizer.h"
#include "FruitfulSoil.h"

Fertilizer::Fertilizer(CropField *cropField)
    : CropField(cropField->getCropType(), cropField->getTotalCapacity(), cropField->getUnitID(), cropField->getLocation(), cropField->getEnergyConsumption(),cropField->getYield()), cropField(cropField) {}

int Fertilizer::getTotalCapacity()
{
    return cropField->getTotalCapacity();
}

string Fertilizer::getCropType()
{
    return cropField->getCropType();
}

string Fertilizer::getUnitID()
{
    return cropField->getUnitID();
}

string Fertilizer::getLocation()
{
    return cropField->getLocation();
}

double Fertilizer::getEnergyConsumption()
{
    return cropField->getEnergyConsumption();
}

double Fertilizer::getSensorData(string sensor) const
{
    return cropField->getSensorData(sensor);
}

void Fertilizer::updateSensorData(string sensor, double value)
{
    cropField->updateSensorData(sensor, value);
}

void Fertilizer::increaseProduction()
{
    if (cropField->getSoilStateName() == "Dry")
    {
        cropField->setSoilState(new FruitfulSoil());
        std::cout << "Fertilizer applied. Soil state changed to Fruitful." << std::endl;
    }
}

int Fertilizer::harvest()
{
    return cropField->harvestCrops(cropField);
}
