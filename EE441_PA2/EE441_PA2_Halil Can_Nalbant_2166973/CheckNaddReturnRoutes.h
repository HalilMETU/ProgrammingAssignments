void CheckNaddReturnRoutes(Routes &G, FlightStack& List){
//Routes are checked one by one with a nested for loops and
//added routes are stored to be used in addMonthlyFlights
FlightStack temp;
cout<<"Missing Return Routes"<<endl;
    for(int i=1;i<mSize+1;i++)
        for(int j=1;j<mSize+1;j++)
            if(!G.isGroute(i,j))
                if(G.isGroute(j,i)){
                    G.addGroute(i,j,rand()%99+1,1);
                    temp.Push(i*100+j);
                    }

cout<<endl<<endl;

while(!temp.Empty()){
    List.Push(temp.Pop());
}






}
