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

// DEMO MAIN STUFF
#include <iostream>
#include <iomanip> // for std::setw
#include <chrono>
#include <thread>

// Color codes
#define RESET "\033[0m"
#define UNDERLINE "\033[4m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define CYAN "\033[36m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define BOLD "\033[1m"

void printHeader(const std::string &title)
{
    // std::cout << BOLD << CYAN << std::setw(50) << std::setfill('=') << "\n" << RESET;
    std::cout << BOLD << BLUE << std::setw(25) << title << RESET << "\n";
    // std::cout << BOLD << CYAN << std::setw(50) << std::setfill('=') << "\n" << RESET;
}
void typewriterEffect(const string &text, int delay)
{
    for (const char &c : text)
    {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(delay));
    }
}

int main()
{

    cout << endl
         << endl
         << RESET << endl;
    typewriterEffect(GREEN BOLD "╔═══════════════════════════════════════════════════════════════════════╗\n", 30);

    // Middle text
    typewriterEffect("║                      Welcome to A & A's FRESH FARM MARKET...          ║\n", 30);

    // Bottom border
    typewriterEffect("╚═══════════════════════════════════════════════════════════════════════╝\n", 30);

    typewriterEffect(YELLOW BOLD "Let's check out some great produce here, shall we..??", 30);
    cout << endl
         << endl;
    typewriterEffect(YELLOW BOLD "Loading..", 50);

    cout << RESET << endl
         << endl;

    typewriterEffect(YELLOW BOLD "\u25CF\u25CF\u25CF\u25CF\u25CF\u25CF\u25CF\u25CF\u25CF\u25CF\u25CF\u25CF\u25CF\u25CF\u25CF\u25CF\u25CF\u25CF\u25CF\u25CF\u25CF\u25CF", 50);

    cout << RESET << endl
         << endl;

    cout << endl
         << endl;

    // Step 1: Create CropField objects (reused across all components)
    CropField *cornField = new CropField("Corn", 100, "CF001", "North Field", 50.0, 20);
    CropField *wheatField = new CropField("Wheat", 150, "CF002", "South Field", 40.0, 25);
    CropField *soybeanField = new CropField("Soybean", 200, "CF003", "South-West Field", 60.0, 85);
    CropField *riceField = new CropField("Rice", 300, "CF004", "East Field", 30.0, 95);
    CropField *maizeField = new CropField("Maize", 100, "CF005", "West-side", 78.6, 100);

    // Step 2: Create a CompositeFarm and add the CropField objects
    CompositeFarm *mainFarm = new CompositeFarm("A & A'S FF MARKET", "Main Farm Location", 50.0);
    mainFarm->addUnit(cornField);
    mainFarm->addUnit(wheatField);
    mainFarm->addUnit(soybeanField);
    mainFarm->addUnit(riceField);
    mainFarm->addUnit(maizeField);

    cout << RED UNDERLINE " TODAY'S FIELDS INCLUDE : " << RESET << endl;

    // std::cout << "Breadth-First Traversal:\n";
    BreadthFirstTraversal bfs(mainFarm);
    while (!bfs.isDone())
    { 
        FarmUnit *current = bfs.next();
        if (current != nullptr)
        {
            cout << GREEN << "\u25CF" << current->getName() << std::endl;
        }
    }
    cout << endl;

    cornField->displayDetails();
    wheatField->displayDetails();
    soybeanField->displayDetails();
    riceField->displayDetails();
    maizeField->displayDetails();
    cout<<endl<<endl;
    mainFarm->displayD();
    cout <<RESET<<endl;

    // Step 3: Soil State Transitions & Harvesting
    printHeader("----------- LETS SEE THE SOIL CONDITIONS ----------");
    cout << endl;
    typewriterEffect(RED "TEMPERATURES HAVE BEEN HIGH.. DRY SEASON HAS DAMAGED THE FIELDS ", 40);
    cout << endl
         << endl;
    std::cout << BOLD << "INITIAL SOIL STATE " << RESET << "for Wheat Field:" << wheatField->getSoilStateName() << std::endl;

    DrySoil drySoil;
    int yield = drySoil.harvestCrops(wheatField);
    wheatField->setTotalCapacity(yield);
    std::cout << GREEN << "Dry Soil has generated the following crop yield this season : Only " << yield << " units of crops harvested. :( \n"
              << endl
              << endl
              << RESET;

    typewriterEffect(YELLOW "RAINY SEASON HAS COME... LET'S SEE HOW THE HARVEST HAS CHANGED...  ", 40);
    cout << endl
         << endl;
    wheatField->rain(wheatField, 18.0); // Simulate rain transition
    std::cout << CYAN BOLD << "AFTER RAIN , " << RESET CYAN << " soil state for Wheat Field: " << wheatField->getSoilStateName() << std::endl;

    FruitfulSoil fruitfulSoil;
    yield = fruitfulSoil.harvestCrops(wheatField);
    wheatField->setTotalCapacity(yield);
    cout << "YAYYYYYY!!!!!!!!!!! " << endl;
    std::cout << GREEN << "Fruitful Soil has generated the following yield this season : " << yield << " units of crops harvested. :) \n" << RESET;
    cout << endl<< endl;

    wheatField->rain(wheatField, 26);
    std::cout<<RED << "After MORE RAIN, state of the soil has changed to : " << wheatField->getSoilStateName() << RESET <<std::endl;
    cout << endl<< endl;
    std::cout << GREEN << "Fruitful Soil has generated the following yield this season : " << yield << " units of crops harvested. :) \n"
              << RESET;
    cout << endl
         << endl;

    // Step 4: Truck Operations
    typewriterEffect(CYAN "++++++++++++++++++++++++++++TRUCKS FOR FIELDS++++++++++++++++++++++++++++++++ ", 40);
    cout << RESET << endl;
    // mainFarm->displayD();

    cout << endl
         << endl;
    typewriterEffect(MAGENTA UNDERLINE "=== BUYING TRUCKS FOR A and A'S FF MARKET ===", 40);
    cout << std::endl
         << RESET << endl;
    Truck *truck = riceField->buyTruck("DeliveryTruck", 100, 1, 200);
    cout << endl;
    Truck *truck2 = wheatField->buyTruck("FertilizerTruck", 468, 55, 200);
    cout << endl;
    Truck *truck3 = maizeField->buyTruck("FertilizerTruck", 468, 20, 200);
    cout << endl;

    DeliveryTruck *dtk = dynamic_cast<DeliveryTruck *>(truck);
    cout << endl;
    FertilizerTruck *ftk = dynamic_cast<FertilizerTruck *>(truck2);
    cout << endl;
    FertilizerTruck *ftk2 = dynamic_cast<FertilizerTruck *>(truck3);
    cout << endl;

    cout << RESET << endl;
    riceField->notifyTrucks();
    cout << endl;
    std::cout << "Count of delivery truck for rice field : " << dtk->getCallCounter() << std::endl
              << endl;
    wheatField->notifyTrucks();
    std::cout << "Count of fertilizer truck for wheat field: " << ftk->getCallCounter() << std::endl
              << endl;
    maizeField->notifyTrucks();
    std::cout << "Count of fertilizer truck for maize field: " << ftk2->getCallCounter() << std::endl
              << RESET << endl;

    typewriterEffect(BLUE UNDERLINE "\n=== NOTIFYING A SPECIFIC TRUCK ===\n", 40);
    cout << RESET << endl;
    maizeField->notifyTruck(ftk2);

    riceField->currStorageCap();
    cout << endl;
    riceField->currSoilState();
    cout << endl;

    wheatField->currStorageCap();
    cout << endl;
    wheatField->currSoilState();
    cout << endl;

    typewriterEffect(CYAN UNDERLINE "===ASSESSING IF UNIT CONTAINS UNUSED TRUCKS===", 40);
    cout << RESET << endl;
    riceField->sellTruck();
    wheatField->sellTruck();
    maizeField->sellTruck();

    typewriterEffect(GREEN UNDERLINE "\n===TOTAL TRUCKS IN THE FARM UNIT:===\n", 40);
    cout << RESET << endl;
    std::cout << "Total trucks in THE RICE FIELD: " << riceField->getCount() << std::endl;
    std::cout << "Total trucks in THE WHEAT FIELD: " << wheatField->getCount() << std::endl;
    std::cout << "Total trucks in MAIZE FIELD: " << maizeField->getCount() << std::endl;

    typewriterEffect(CYAN UNDERLINE "\n=== TIME TO ADD MORE TRUCKS:===\n", 40);
    cout << RESET << endl;
    mainFarm->addTruck(dtk);
    cout << endl;
    mainFarm->addTruck(ftk);
    cout << endl;
    mainFarm->addTruck(ftk2);
    cout << endl;

    typewriterEffect( GREEN UNDERLINE "\n===REMOVING TRUCKS FROM UNIT :===\n", 40);
    cout << RESET <<endl;
    mainFarm->removeTruck(dtk);cout<<endl;
    mainFarm->removeTruck(ftk2);cout<<endl;
    std::cout<<"Total Trucks in Farm: "<<mainFarm->getTruckCount()<<std::endl;

   
    
//=====================================================================================
    // Step 5: Sensor Data Update
    typewriterEffect(RED UNDERLINE "\n===UPDATE THE FARM UNIT SENSORS :===\n", 40);
    cout << RESET;
    mainFarm->updateSensorData("Temperature", 50.60);
    std::cout << "Updating the temperature sensors of the farm  to : " << mainFarm->getSensorData("Temperature") << RESET << endl
              << std::endl;

    cornField->updateSensorData("Moisture", 25.5);
    std::cout << "Corn Field Moisture Level: " << cornField->getSensorData("Moisture") << std::endl;

    // Step 6: Fertilizer and Extra Barn Enhancements
    Fertilizer *ftl = new Fertilizer(cornField);
    cout << endl;
    cout << GREEN;
    ftl->increaseProduction();
    cout << endl;
    cout << RESET;

    int newYield = ftl->harvest();
    cout << endl;
    std::cout << "Increased Yield: " << newYield << std::endl;

    ExtraBarn *barn = new ExtraBarn(cornField, 50);
    cout << endl;
    barn->add();
    cout << endl;
    int cap = barn->getLeftoverCapacity();
    std::cout << "Total increased capacity after an extra barn: " << RED << cap << RESET << endl
              << std::endl;

    typewriterEffect(RED UNDERLINE "\n===LETS REVIEW OUR FARMS ONCE AGAIN :===\n", 40);
    cout << RESET << endl;
    DepthFirstTraversal dfs(mainFarm);
    while (!dfs.isDone())
    {
        FarmUnit *current = dfs.next();
        if (current != nullptr)
        {
            cout << BLUE << "\u25CF" << current->getName() << std::endl;
        }
    }
    cout  << RESET <<endl;

    typewriterEffect( RED  "\n+++++++++++++THANK YOU, COME AGAIN +++++++++++++\n", 40);
    cout <<RESET<<endl;

    typewriterEffect( BOLD "\u25CF\u25CF\u25CF\u25CF\u25CF\u25CF\u25CF\u25CF\u25CF\u25CF\u25CF\u25CF\u25CF\u25CF\u25CF\u25CF\u25CF\u25CF\u25CF\u25CF\u25CF\u25CF", 50);
    cout <<RESET<<endl;
    cout << endl;

    // Clean up dynamically allocated memory
    delete mainFarm;
    return 0;
}