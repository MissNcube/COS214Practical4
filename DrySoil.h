#ifndef DRYSOIL_H
#define DRYSOIL_H
#include <iostream>
#include <string>
using namespace std;

#include "SoilState.h"
#include "CropField.h"

class DrySoil : public SoilState
{
    
    public:
        virtual ~DrySoil() = default;
        int harvestCrops(CropField* crop) override;
        void rain(CropField* field, double rainAmt) override;
        string getName() const override;

};
#endif //DRYSOIL_H