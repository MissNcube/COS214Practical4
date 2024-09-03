#include "DrySoil.h"
#include "FruitfulSoil.h"
#include "CropField.h"
#include <iostream>


int DrySoil::harvestCrops(CropField *crop)
{
    std::cout << "Minimal yield due to dry soil." << std::endl;
    int yield = crop->getYield();
    yield *=1;
    crop->setYield(yield);
    return yield;
    // return 1;  // Yield multiplier for dry soil
}

void DrySoil::rain(CropField* field, double rainAmt) {
    if(rainAmt > 15)
    {
        std::cout << "Rain has improved soil from Dry to Fruitful." << std::endl;
        field->setSoilState(new FruitfulSoil());
    }
    else 
    {
        std::cout << "Rain is insufficient, soil is very dry" << std::endl;
    }
    
}

std::string DrySoil::getName() const {
    return "Dry";
}

