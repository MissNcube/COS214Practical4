#include <iostream>
#include "CropField.h"
#include "CompositeFarm.h"
#include "FarmUnit.h"
#include "FloodedSoil.h"

void testComponent1();
void testComponent2();

int main()
{
    // testComponent1();
    testComponent2();
    return 0;
}

void testComponent1()
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

void testComponent2()
{
      // Create a CropField instance
    CropField* wheatField = new CropField("Wheat", 100, "CF001", "North Field", 500.0);
    CompositeFarm*  myFarm = new CompositeFarm("Farm001", "Main Farm Location", 50.0);
    CropField*  cornField = new CropField("Corn", 150, "CF002", "Field 2",300.0);
    myFarm->addUnit(wheatField);
    myFarm->addUnit(cornField);

    // Display the initial state of the soil
    std::cout << "Initial soil state: " << wheatField->getSoilStateName() << std::endl;

    // Harvest crops in the initial state (DrySoil)
    DrySoil dy;
    int yield = dy.harvestCrops(wheatField);
    wheatField->setTotalCapacity(yield);
    std::cout << "Yield: " << yield<<" units of crops harvested." << std::endl;
   std::cout<< wheatField->getTotalCapacity()<<std::endl;

    double rainfall = 18.0;
    // Simulate rain which should transition from DrySoil to FruitfulSoil
    wheatField->rain(wheatField, rainfall);
    std::cout << "After rain, soil state: " << wheatField->getSoilStateName() << std::endl;

    // Harvest crops in the new state (FruitfulSoil)
    FruitfulSoil fs;
    int yield2 = fs.harvestCrops(wheatField);
    wheatField->setTotalCapacity(yield2);
    std::cout << "Yield: " << yield2 << " times units of crops harvested." << std::endl;
    std::cout<< wheatField->getTotalCapacity()<<std::endl;
     std::cout<<"Total Capacity of farm: "<<myFarm->getTotalCapacity()<<std::endl;


    //  Set the soil state to FloodedSoil manually to test it
    wheatField->setSoilState(new FloodedSoil());
     std::cout << "Manually set soil state: " << wheatField->getSoilStateName() << std::endl;

    // // Harvest crops in the FloodedSoil state
    FloodedSoil fs2;
    int yield3 = fs2.harvestCrops(wheatField);
    wheatField->setTotalCapacity(yield3);
    std::cout << "Yield: " << yield3 << " times units of crops harvested." << std::endl;
    std::cout<< wheatField->getTotalCapacity()<<std::endl;

       
    // Simulate rain in the FloodedSoil state
    wheatField->rain(wheatField, 15);
    std::cout << "After more rain, soil state: " << wheatField->getSoilStateName() << std::endl;

delete cornField;
delete wheatField;
}