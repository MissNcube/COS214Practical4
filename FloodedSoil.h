// FloodedSoil.h
#ifndef FLOODED_SOIL_H
#define FLOODED_SOIL_H

#include "SoilState.h"
#include "FruitfulSoil.h"
#include "DrySoil.h"

class FloodedSoil : public SoilState {
public:
    virtual ~FloodedSoil() = default;
    int harvestCrops(CropField* crop) override;
    void rain(CropField* field, double rainAmt) override;
    std::string getName() const override;
};

#endif // FLOODED_SOIL_H
