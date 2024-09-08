#include <iostream>
#include "CompositeFarm.h"
#include "CropField.h"
#include "FarmUnit.h"
#include "FloodedSoil.h"
#include "Fertilizer.h"
#include "ExtraBarn.h"
#include "DeliveryTruck.h"
#include "FertilizerTruck.h"
#include "TruckFactory.h"
#include "FarmTraversal.h"
#include "DepthFirstTraversal.h"
#include "BreadthFirstTraversal.h"
#include "DrySoil.h"
#include "FruitfulSoil.h"
#include "Notifications.h"
#include "Truck.h"


void testComponent1();
void testComponent2();
void testComponent3();
void testComponent4();
void testComponent5();
void testAll();

int main()
{

    testComponent1();
    testComponent2();
    testComponent3();
    testComponent4();
    testComponent5();
    testAll();
    return 0;
}

void testComponent1()
{
    
    CropField *cornField = new CropField("Corn", 100, "CF001", "Field 1", 10.0, 20);
    std::cout << "+++++++++++++++++++CORNFIELD DATA+++++++++++++++++++++" << std::endl;
    cornField->displayDetails();
    cornField->updateSensorData("Pest Control(sPs/ml)" , 880);
    std::cout<<"Increased the pest control sensor to : " << cornField->getSensorData("Pest Control(sPs/ml)")<<std::endl;


    CropField *wheatField = new CropField("Wheat", 150, "CF002", "Field 2", 15.0, 40);
    std::cout << "+++++++++++++++++++WheatField DATA+++++++++++++++++++++" << std::endl;
    wheatField->displayDetails();
    wheatField->updateSensorData("Moisture Level(%)", 70);
    std::cout<<"Inceased the moisture to: "<<wheatField->getSensorData("Moisture Level(%)")<<std::endl;



    std::cout << "+++++++++++++++++++FARM DATA+++++++++++++++++++++" << std::endl;
    CompositeFarm *myFarm = new CompositeFarm("Farm001", "Main Farm Location", 50.0);
    myFarm->addUnit(cornField);
    myFarm->addUnit(wheatField);
    std::cout << "Total Capacity of the Farm: " << myFarm->getTotalCapacity() << std::endl;
    std::cout << "Crop Types in the Farm: " << myFarm->getCropType() << std::endl;
    std::cout << "Unit IDs in the Farms: " << myFarm->getUnitID() << std::endl;
    std::cout << "Locations in the Farms: " << myFarm->getLocation() << std::endl;
    std::cout << "Energy Consumption of the Farm(kWh): " << myFarm->getEnergyConsumption() << std::endl;
    cornField->updateSensorData("Moisture", 25.5);
    std::cout << "Corn Field Moisture: " << cornField->getSensorData("Moisture") << std::endl;
    wheatField->updateSensorData("Temperature", 28.0);
    std::cout << "Wheat Field Temperature: " << wheatField->getSensorData("Temperature") << std::endl;
    delete myFarm;

}

void testComponent2()
{
    // Create a CropField instance
    CropField *wheatField = new CropField("Wheat", 100, "CF001", "North Field", 500.0, 60);
    CompositeFarm *myFarm = new CompositeFarm("Farm001", "Main Farm Location", 50.0);
    CropField *cornField = new CropField("Corn", 150, "CF002", "Field 2", 300.0, 45);
    myFarm->addUnit(wheatField);
    myFarm->addUnit(cornField);

    // Display the initial state of the soil
    std::cout << "Initial soil state: " << wheatField->getSoilStateName() << std::endl;

    // Harvest crops in the initial state (DrySoil)
    DrySoil dy;
    int yield = dy.harvestCrops(wheatField);
    wheatField->setTotalCapacity(yield);
    std::cout << "Yield: " << yield << " units of crops harvested." << std::endl;
    std::cout << wheatField->getTotalCapacity() << std::endl;

    double rainfall = 18.0;
    // Simulate rain which should transition from DrySoil to FruitfulSoil
    wheatField->rain(wheatField, rainfall);
    std::cout << "After rain, soil state: " << wheatField->getSoilStateName() << std::endl;

    // Harvest crops in the new state (FruitfulSoil)
    FruitfulSoil fs;
    int yield2 = fs.harvestCrops(wheatField);
    wheatField->setTotalCapacity(yield2);
    std::cout << "Yield: " << yield2 << " times units of crops harvested." << std::endl;
    std::cout << wheatField->getTotalCapacity() << std::endl;
    std::cout << "Total Capacity of farm: " << myFarm->getTotalCapacity() << std::endl;

    //  Set the soil state to FloodedSoil manually to test it
    wheatField->setSoilState(new FloodedSoil());
    std::cout << "Manually set soil state: " << wheatField->getSoilStateName() << std::endl;

    // // Harvest crops in the FloodedSoil state
    FloodedSoil fs2;
    int yield3 = fs2.harvestCrops(wheatField);
    wheatField->setTotalCapacity(yield3);
    std::cout << "Yield: " << yield3 << " times units of crops harvested." << std::endl;
    std::cout << wheatField->getTotalCapacity() << std::endl;

    // Simulate rain in the FloodedSoil state
    wheatField->rain(wheatField, 15);
    std::cout << "After more rain, soil state: " << wheatField->getSoilStateName() << std::endl;

    // delete cornField;
    // delete wheatField;
    delete myFarm;
}

void testComponent3()
{
    CropField *cornField = new CropField("Tomatoes", 1000, "Field1", "North", 200, 50);
    CropField *potatoes = new CropField("Potato", 900, "CFT8", "Section6", 150, 50);
    CompositeFarm *farm1 = new CompositeFarm("OpenLand", "SpringField", 400);

    Fertilizer *ftl = new Fertilizer(cornField);
    ftl->increaseProduction();

    int yield = ftl->harvest();
    std::cout << "Increased Yield: " << yield << std::endl;

    ExtraBarn *barn = new ExtraBarn(cornField, 50);
    barn->add();
    int cap = barn->getLeftoverCapacity();
    std::cout << "Total increased capacity after an extra barn: " << cap << std::endl;

    farm1->addUnit(cornField);
    farm1->addUnit(potatoes);
    std::cout << "++++++++++++++++++++FARM DATA++++++++++++++++++++++ " << std::endl;
    farm1->displayD();
}

void testComponent4()
{
    std::cout << "++++++++++++++++++++++++++++++++CROPS++++++++++++++++++++++++++++++++++++++ " << std::endl;
    CropField* wheatField = new CropField("Wheat", 1500, "CF01", "North Field", 50.5, 500);
    CropField* potatoField = new CropField("Potato" , 2500 , "GYG8" , "South Corner" , 690 , 800);
    CropField* sugarcaneField = new CropField("SugarCane" , 3000,"DG8J" , "Central Farm" , 100 , 1200);
    CropField* sunflowerField =  new CropField("Sunflower" , 2000 , "FDF9" , "Down East" , 80 , 600);
    std::cout<<"Details of crops: "<<std::endl;
    wheatField->displayDetails();
    potatoField->displayDetails();
    sugarcaneField->displayDetails();
    sunflowerField->displayDetails();
    std::cout << "++++++++++++++++++++++++++++++++FARM++++++++++++++++++++++++++++++++++++++++ " << std::endl;
    CompositeFarm* farm = new CompositeFarm("SIMBAFARM" , "North West" , 1500);
    farm->addUnit(wheatField);
    farm->addUnit(potatoField);
    farm->addUnit(sugarcaneField);
    farm->addUnit(sunflowerField);
    farm->displayD();
    std::cout << "++++++++++++++++++++++++++++TRUCKS FOR FIELDS++++++++++++++++++++++++++++++++ " << std::endl;
    std::cout << "=== Buying Trucks ===" << std::endl;
    Truck * truck =  wheatField->buyTruck("DeliveryTruck", 100, 1, 200);
    DeliveryTruck* dtk = dynamic_cast<DeliveryTruck*>(truck);
    Truck* truck2 = potatoField->buyTruck("FertilizerTruck",468,55,200);
    FertilizerTruck* ftk = dynamic_cast<FertilizerTruck*>(truck2);
    Truck* truck3 = sugarcaneField->buyTruck("FertilizerTruck",468,20,200);
    FertilizerTruck* ftk2 = dynamic_cast<FertilizerTruck*>(truck3);
    Truck* truck4 = sunflowerField->buyTruck("DeliveryTruck",580,31,880);
    DeliveryTruck* dtk2 = dynamic_cast<DeliveryTruck*>(truck4);

    std::cout << "\n=== Notifying Trucks ===" << std::endl;
    wheatField->notifyTrucks();
    std::cout<<"Count of delivery truck for wheatfield: "<<dtk->getCallCounter()<<std::endl;
    potatoField->notifyTrucks();
    std::cout<<"Count of fertilizer truck for potatofield: "<<ftk->getCallCounter()<<std::endl;
    sugarcaneField->notifyTrucks();
    std::cout<<"Count of fertilizer truck for potatofield: "<<ftk2->getCallCounter()<<std::endl;
    // sunflowerField->notifyTrucks();
    std::cout<<"Count of delivery truck for sunflowerfield: "<<dtk2->getCallCounter()<<std::endl;


    std::cout<<"Details of crops: "<<std::endl;
    wheatField->displayDetails();
    potatoField->displayDetails();
    sugarcaneField->displayDetails();
    sunflowerField->displayDetails();

    std::cout << "\n=== Notifying a specific Truck ===" << std::endl;
    sugarcaneField->notifyTruck(ftk2);
    std::cout<<"Details of crop: "<<std::endl;
    sugarcaneField->displayDetails();


    std::cout << "\n=== Simulate Crop Storage Capacity and When soil is dry===" << std::endl;
    wheatField->currStorageCap();  
    wheatField->currSoilState(); 
    std::cout<<"Details of wheatField: "<<std::endl;
    wheatField->displayDetails();
    potatoField->currStorageCap();  
    potatoField->currSoilState(); 
    std::cout<<"Details of potatoField: "<<std::endl; 
    potatoField->displayDetails();
       
    sugarcaneField->currStorageCap();  
    sugarcaneField->currSoilState(); 
    std::cout<<"Details of sugarcaneField: "<<std::endl;  
    sugarcaneField->displayDetails(); 

    std::cout << "\n===Attempting to sell an unused truck===" << std::endl;
    sunflowerField->sellTruck();
    std::cout << "\n===Attempting to sell a used truck===" << std::endl;
    wheatField->sellTruck();
    sugarcaneField->sellTruck();
    potatoField->sellTruck();

    std::cout << "++++++++++++++++++++++++++++TRUCKS FOR Farm++++++++++++++++++++++++++++++++ " << std::endl;

    std::cout << "\n===Total trucks in each field:===" << std::endl;
    std::cout<<"Total trucks in wheatField: "<<wheatField->getCount()<<std::endl;
    std::cout<<"Total trucks in potatoField: "<<potatoField->getCount()<<std::endl;
    std::cout<<"Total trucks in sugarcaneField: "<<sugarcaneField->getCount()<<std::endl;
    std::cout<<"Total trucks in sunflowerField: "<<sunflowerField->getCount()<<std::endl;
    std::cout << "\n===Total trucks in the farm:===" << std::endl;
    farm->addTruck(dtk);
    farm->addTruck(ftk);
    farm->addTruck(ftk2);
    farm->addTruck(dtk2);
     std::cout << "\n===Removing some trucks from the farm:===" << std::endl;
     farm->removeTruck(dtk);
     farm->removeTruck(ftk2);
     std::cout<<"Total Trucks in Farm: "<<farm->getTruckCount()<<std::endl;
    farm->updateSensorData("Temperature" , 50.60);
    std::cout<<"Updating the temperature sensors of the farm  to : "<<farm->getSensorData("Temperature")<<std::endl;

}

void testComponent5()
{
    // Create farm units
    CropField *cornField = new CropField("Corn", 100, "CF001", "North Field", 50.0, 20);
    CropField *wheatField = new CropField("Wheat", 150, "CF002", "South Field", 40.0, 25);
    CropField *soybeanField = new CropField("Soybean", 200, "CF003", "South-West Field", 60.0, 85);
    CropField *riceField = new CropField("Rice", 300, "CF004", "East Field", 30.0, 95);
    CropField *maizefield = new CropField("Maize", 100, "CF005", "West-side", 78.6, 100);

    // Create composite farms and add farm units to them
    CompositeFarm *mainFarm = new CompositeFarm("Farm001", "Main Farm Location", 50.0);
    mainFarm->addUnit(cornField);
    mainFarm->addUnit(wheatField);
    mainFarm->addUnit(soybeanField);
    mainFarm->addUnit(riceField);
    mainFarm->addUnit(maizefield);

    // Breadth-First Traversal
    std::cout << "Breadth-First Traversal:" << std::endl;
    BreadthFirstTraversal bfs(mainFarm); // Start from the root, mainFarm

    while (!bfs.isDone())
    {
        FarmUnit *current = bfs.next();
        if (current != nullptr)
        {
            std::cout << "Visiting: " << current->getName() << std::endl;
        }
    }

    std::cout << std::endl;

    // Depth-First Traversal
    std::cout << "Depth-First Traversal:" << std::endl;
    DepthFirstTraversal dfs(mainFarm); // Start from the root, mainFarm

    while (!dfs.isDone())
    {
        FarmUnit *current = dfs.next();
        if (current != nullptr)
        {
            std::cout << "Visiting: " << current->getName() << std::endl;
        }
    }

    // Clean up dynamically allocated memory
    delete mainFarm; // This should recursively delete the other farm units
}

void testAll()
{
    
}
