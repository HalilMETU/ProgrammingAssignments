void CancelUnpopularFlights(FTr &F, FlightStack& Prev, FlightStack& List2){
FlightStack temp;
int flightnumber=0;int i=0;
while(!Prev.Empty()){
    flightnumber=Prev.Pop();//prev contains last months unpopular flights
    if(F.getOccupancyState(flightnumber)<OSTreshold){//if they are still unpopular
        if(i==0){
            cout<<"Cancelled Flights:"<<endl;
            i++;}
        F.REMOVETFLIGHT(flightnumber);
        temp.Push(flightnumber);//cancelled flights are stored to remove the routes
        }
}
if(i==1)
cout<<endl;
while(!temp.Empty())
        List2.Push(temp.Pop());//temp is reversed to get a list in-order
}

