// FruitfulSoil.h
#ifndef FRUITFUL_SOIL_H
#define FRUITFUL_SOIL_H

#include "SoilState.h"
#include "CropField.h"
#include "FloodedSoil.h"

class FruitfulSoil : public SoilState {
public:
    virtual  ~FruitfulSoil() =  default;
    int harvestCrops(CropField* crop) override;
    void rain(CropField* field, double rainAmt) override;
    std::string getName() const override;
};

#endif // FRUITFUL_SOIL_H
