void Monthly(Routes &G,FTr &F,FlightStack& CancelF,FlightStack& S){
    AddMonthlyNewRoutes(G,F,S);//added routes are stored in S
    AddMonthlyNewFlights(F,S);//flights in S added to F

    F.randomOCS();//we receive occRate of the current month(assigning random Occupancy Rates)
    CancelUnpopularFlights(F, CancelF, S);
    //Current Occupancy rates are compared with previous months low occupancy flights
    //previous months low occupancy flights are stored in CancelF
    //BST is searched for flights in CancelF and if the found flight is still have low occupancy rate then it is cancelled
    //cancelled flights stored in S to be used to remove routes
    DiscardUnpopularRoutesAndPrices(F,G,S);//Routes removed using the information in S
    F.getLowOS(CancelF);//CancelF is renewed with low occupancy flights of this month(not cancelled)

    //displaying all available routes and then Flights
    G.ListGroutes();
    F.display();
    }

