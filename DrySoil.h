#ifndef DRYSOIL_H
#define DRYSOIL_H
#include <iostream>
#include <string>
#include "SoilState.h"
#include "CropField.h"
#include "FruitfulSoil.h"
using namespace std;

class DrySoil : public SoilState
{

public:
    virtual ~DrySoil() = default;
    int harvestCrops(CropField *crop) override;
    void rain(CropField *field, double rainAmt) override;
    string getName() const override;
};
#endif 