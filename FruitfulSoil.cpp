// FruitfulSoil.cpp
#include "FruitfulSoil.h"
#include <iostream>


int FruitfulSoil::harvestCrops(CropField *crop)
{
    std::cout << "Abundant yield due to fruitful soil!" << std::endl;
    int yield = crop->getTotalCapacity();
    yield *= 3;
     crop->setTotalCapacity(yield);
    return  yield;
    // return 3;  // Yield multiplier for fruitful soil
}

void FruitfulSoil::rain(CropField* field, double rainAmt) {
    if(rainAmt > 25)
    {
        std::cout << "Rain has worsened soil from fruitful to flooded." << std::endl;
        field->setSoilState(new FloodedSoil());
    }
    else 
    {
        std::cout << "Rain is still in great condition, soil is very fruitful" << std::endl;
    }
}

std::string FruitfulSoil::getName() const {
    return "Fruitful";
}
