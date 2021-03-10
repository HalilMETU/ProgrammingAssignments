
void AddMonthlyNewRoutes(Routes& Gcity,FTr& TFlight, FlightStack &List){
    cout<<"Monthly New Route Offers"<<endl;
    int i=0;
    int c1,c2,w;
    FlightStack temp;

    while(i<N){

        c1=rand()%20+1;
        c2=rand()%20+1;
        if(c1!=c2){
            if(TFlight.SEARCHTFLIGHT(c1*100+c2)==NULL){//add the flight if flight does not exist in the BST
                w=rand()%99+1;
                Gcity.addGroute(c1,c2,w,1);
                temp.Push(c1*100+c2);//flights are saved to be added to BST
                i++;
            }
        }
    }


while(!temp.Empty()){
    List.Push(temp.Pop());
}//stack is reversed to preserve in order addition

    cout<<endl;
}


