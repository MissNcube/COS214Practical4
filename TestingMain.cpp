#include <iostream>
#include "CropField.h"
#include "CompositeFarm.h"
#include "FarmUnit.h"

void TestComponent1();

int main()
{
    TestComponent1();
    return 0;
}

void TestComponent()
{
     // Create some CropField instances
    CropField* cornField = new CropField("Corn", 100, "CF001", "Field 1", 10.0);
    CropField* wheatField = new CropField("Wheat", 150, "CF002", "Field 2", 15.0);
    
    // Create a CompositeFarm
    CompositeFarm* myFarm = new CompositeFarm("Farm001", "Main Farm Location", 50.0);

    // Add CropFields to the CompositeFarm
    myFarm->addUnit(cornField);
    myFarm->addUnit(wheatField);

    // Test getTotalCapacity
    std::cout << "Total Capacity of the Farm: " << myFarm->getTotalCapacity() << std::endl;

    // Test getCropType
    std::cout << "Crop Type in the Farm: " << myFarm->getCropType() << std::endl;

    // Test getSoilStateName
    std::cout << "Soil State Name: " << myFarm->getSoilStateName() << std::endl;

    // Test sensor data management
    cornField->updateSensorData("Moisture", 25.5);
    std::cout << "Corn Field Moisture: " << cornField->getSensorData("Moisture") << std::endl;

    // Clean up memory
    delete myFarm; // This will also delete all child CropField instances
}