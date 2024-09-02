#include <iostream>
#include "CropField.h"
#include "CompositeFarm.h"
#include "FarmUnit.h"



void testComponent();

int main()
{
    testComponent();
    return 0;
}

void testComponent()
{
     // Create some CropField instances
    CropField* cornField = new CropField("Corn", 100, "CF001", "Field 1", 10.0);
  std::cout<<"+++++++++++++++++++CORNFIELD DATA+++++++++++++++++++++"<<std::endl  
    <<cornField->getCropType()<<" "
    <<cornField->getTotalCapacity()<<" "
     <<cornField->getUnitID()<<" "
    <<cornField->getLocation()<<" "
    <<cornField->getEnergyConsumption()<<" "
    <<std::endl;


    CropField* wheatField = new CropField("Wheat", 150, "CF002", "Field 2", 15.0);
    std::cout<<"+++++++++++++++++++WheatField DATA+++++++++++++++++++++"<<std::endl  
    <<wheatField->getCropType()<<" "
    <<wheatField->getTotalCapacity()<<" "
     <<wheatField->getUnitID()<<" "
    <<wheatField->getLocation()<<" "
    <<wheatField->getEnergyConsumption()<<" "
    <<std::endl;

    
    // Create a CompositeFarm
    CompositeFarm* myFarm = new CompositeFarm("Farm001", "Main Farm Location", 50.0);
    std::cout<<"+++++++++++++++++++FARM DATA+++++++++++++++++++++"<<std::endl ;
    // Add CropFields to the CompositeFarm
    myFarm->addUnit(cornField);
    myFarm->addUnit(wheatField);
    // Test getTotalCapacity
    std::cout << "Total Capacity of the Farm: " << myFarm->getTotalCapacity() << std::endl;
    // Test getCropType
    std::cout << "Crop Types in the Farm: " << myFarm->getCropType() << std::endl;
    // Test getUnitID
    std::cout << "Unit IDs in the Farms: " << myFarm->getUnitID()<<std::endl;
    // Test getLocation
    std::cout << "Locations in the Farms: " << myFarm->getLocation()<<std::endl;
    // Test getEnergyConsumption
    std::cout << "Energy Consumption of the Farm(kWh): " << myFarm->getEnergyConsumption()<<std::endl;
    // Test sensor data management
    cornField->updateSensorData("Moisture", 25.5);
    std::cout << "Corn Field Moisture: " << cornField->getSensorData("Moisture") << std::endl;
    wheatField->updateSensorData("Temperature", 28.0);
    std::cout << "Wheat Field Temperature: " << wheatField->getSensorData("Temperature")<<std::endl;

    delete myFarm; 
}