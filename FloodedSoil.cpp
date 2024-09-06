#include "FloodedSoil.h"
#include <iostream>

int FloodedSoil::harvestCrops(CropField *crop)
{
    std::cout << "No yield due to flooded soil." << std::endl;
    int yield = crop->getYield();
    yield *= 0;
    crop->setYield(yield);
    return yield;
}

void FloodedSoil::rain(CropField *field, double rainAmt)
{
    if (rainAmt < 10)
    {
        std::cout << "Rain has reduced the soil from flooded to dry." << std::endl;
        field->setSoilState(new DrySoil());
    }
    else
    {
        std::cout << "Rain is still very flooded, soil is not good right now" << std::endl;
    }
}

std::string FloodedSoil::getName() const
{
    return "Flooded";
}
