void SemiAnnual(Routes &G, FTr &F, FlightStack &S, FlightStack &CancelF){
    //First month operation
    InitRouteMap(G);
    InitFlightPlan(G,F);

    F.randomOCS();//we receive occRate of the first month
    CancelUnpopularFlights(F, CancelF, S);//remove if the flights are still unpopular
    DiscardUnpopularRoutesAndPrices(F,G,S);
    F.getLowOS(CancelF);//record low occRate flights for next month

    cout << "----------------Month 2------------------:" << endl;
    Monthly(G,F,CancelF,S);
    //monthly contains the following commented lines of code
    /*
    //new routes and flights are added
    AddMonthlyNewRoutes(G,F,S);
    AddMonthlyNewFlights(F,S);

    //operations related to occupancy rate
    F.randomOCS();//we receive occRate of the second month//OccRate randomly assigned
    CancelUnpopularFlights(F, CancelF, S);//removes the consequtively unpopular flights
    DiscardUnpopularRoutesAndPrices(F,G,S);
    F.getLowOS(CancelF);//record low occRate flights for next month

    G.ListGroutes();
    F.display();

    */
    cout << "----------------Month 3------------------:" << endl;
        Monthly(G,F,CancelF,S);
    cout << "----------------Month 4------------------:" << endl;
        Monthly(G,F,CancelF,S);
    cout << "----------------Month 5------------------:" << endl;
        Monthly(G,F,CancelF,S);
    cout << "----------------Month 6------------------:" << endl;

    AddMonthlyNewRoutes(G,F,S);
    AddMonthlyNewFlights(F,S);

    F.randomOCS();//we receive occRate of the sixth month
    CancelUnpopularFlights(F, CancelF, S);
    DiscardUnpopularRoutesAndPrices(F,G,S);
    F.getLowOS(CancelF);//record low occRate flights for next month


    //add missing routes
    CheckNaddReturnRoutes(G,S);
    //add missing flights
    AddReturnFlights(F,S);


    G.ListGroutes();
    F.display();
}
