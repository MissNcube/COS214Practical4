#ifndef EXTRABARN_H
#define  EXTRABARN_H


#include "CropField.h"

class ExtraBarn : public CropField {
private:
    CropField* cropField;
    int additionalCapacity;

public:
    ExtraBarn(CropField* cropField, int additionalCapacity);
    void add();
    int getLeftoverCapacity();
    int getTotalCapacity() override;
    int getYield() override;





};





#endif