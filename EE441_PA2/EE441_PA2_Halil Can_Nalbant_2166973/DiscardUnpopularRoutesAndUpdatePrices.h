void DiscardUnpopularRoutesAndPrices(FTr &F,Routes &G, FlightStack& List){

    int c1,c2;
    FlightStack temp;
    int flightnumber=0;
    int i=0;

    while(!List.Empty()){//using the list created in the CancelUnpopularFlights routes are removed
        flightnumber=List.Pop();
        c1=flightnumber/100;
        c2=flightnumber%100;
        if(i==0){
            cout<<"Discarded Routes & Routes on Discount:"<<endl;
            i++;
        }
        G.removeGroute(c1,c2);
    }
    F.getLowOS(temp);//Unpopular flights are strored in temp to make discounts
    while(!temp.Empty()){
        flightnumber=temp.Pop();
        c1=flightnumber/100;
        c2=flightnumber%100;
        if(i==0){
            cout<<"Discarded Routes & Routes on Discount:"<<endl;
            i++;
        }
        flightnumber=G.getTicketPrice(c1,c2);//halving the ticket prices
        if(flightnumber==1)
            G.setTicketPrice(c1,c2,1);
        else
            G.setTicketPrice(c1,c2,flightnumber/2);
    }


cout<<endl<<endl;
}



