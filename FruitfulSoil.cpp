#include "FruitfulSoil.h"
#include <iostream>

int FruitfulSoil::harvestCrops(CropField *crop)
{
    std::cout << "Abundant yield due to fruitful soil!" << std::endl;
    int yield = crop->getYield();
    yield *= 3;
    crop->setYield(yield);
    return yield;
}

void FruitfulSoil::rain(CropField *field, double rainAmt)
{
    if (rainAmt > 25)
    {
        std::cout << "Rain has worsened soil from fruitful to flooded." << std::endl;
        field->setSoilState(new FloodedSoil());
    }
    else
    {
        std::cout << "Rain is still in great condition, soil is still fruitful" << std::endl;
    }
}

std::string FruitfulSoil::getName() const
{
    return "Fruitful";
}
