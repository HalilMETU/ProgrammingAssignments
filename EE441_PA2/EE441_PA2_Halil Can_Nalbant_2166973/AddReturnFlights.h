void AddReturnFlights(FTr &F,FlightStack &List){
int flightnumber;
cout<<"Missing Return Flights"<<endl;
    while(!List.Empty()){//using the list constructed in CheckandAddReturnRoutes
        flightnumber=List.Pop();
        F.ADDTFLIGHT(flightnumber,1);
    }
cout<<endl<<endl;
}
