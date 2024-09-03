#ifndef FERTILIZER_H
#define FERTILIZER_H

#include "CropField.h"

class Fertilizer : public CropField
{
private:
    CropField *cropField;

public:
    Fertilizer(CropField *cropField);

    int getTotalCapacity() override;
    string getCropType() override;
    string getUnitID() override;
    string getLocation() override;
    double getEnergyConsumption() override;
    double getSensorData(string sensor) const override;
    void updateSensorData(string sensor, double value) override;

    // Enhancing functionality
    void increaseProduction();
    int harvest();

};

#endif