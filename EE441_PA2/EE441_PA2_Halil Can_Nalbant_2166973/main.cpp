using namespace std;
const int mSize=20;//Must be set according to number of cities in citylist.txt
const int N=5;//number of monthly new entries
const int OSTreshold=70;//treshold of occupancy rate
#include <iostream>
#include <fstream>
#include <string>
#include <assert.h>
#include "node.h"
#include "node2.h"
#include "Routes.h"
#include "InitRouteMap.h"
#include "FlightStack.h"
#include "FlightBSTree.h"
#include "InitFlightPlan.h"
#include "AddMonthlyNewRoutes.h"
#include "AddMonthlyNewFlights.h"
#include "CancelUnpopularFlights.h"
#include "DiscardUnpopularRoutesAndUpdatePrices.h"
#include "CheckNaddReturnRoutes.h"
#include "AddReturnFlights.h"
#include "Monthly.h"
#include "SemiAnnual.h"
#include "DisplayRouteOptions.h"

int main()
{
    //Graph to store route prices
    Routes G;

    //BST to store flights
    FTr F;

    //used to convey flights between graph and BST (linked list structure)
    FlightStack S;
    FlightStack CancelF;

    //function for 6 month of operation report
    SemiAnnual(G, F, S, CancelF);

    //Displays route options betwen cities//with numeric and string
    DisplayRouteOptions(G,F,2,11);
    DisplayRouteOptions(G,F,"Analograd","Prokontrolkka");
    DisplayRouteOptions(G,F,10,11);
    DisplayRouteOptions(G,F,"Gulf of Archi","Probia");


    return 0;


}
