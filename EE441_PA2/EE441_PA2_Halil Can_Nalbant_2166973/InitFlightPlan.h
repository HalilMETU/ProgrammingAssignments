void InitFlightPlan(Routes &GR, FTr &FL){

cout<<"Flights:"<<endl;

for(int i=1;i<mSize+1;i++)
        for(int j=1;j<mSize+1;j++)
            if(GR.isGroute(i,j))
                FL.ADDTFLIGHT(100*i+j,0);


cout<<endl;
}
