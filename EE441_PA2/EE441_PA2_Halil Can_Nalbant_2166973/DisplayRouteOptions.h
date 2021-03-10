void DisplayRouteOptions(Routes &G, FTr &F, int c1, int c2);

void DisplayRouteOptions(Routes &G, FTr &F, string cName1, string cName2){
int c1=G.searchGcity(cName1);
int c2=G.searchGcity(cName2);
DisplayRouteOptions(G,F,c1,c2);
};


void DisplayRouteOptions(Routes &G, FTr &F, int c1, int c2){

    string cName1=G.searchGcity(c1);
    string cName2=G.searchGcity(c2);
    string cName3;
    string cName4;
    cout<<"One-way Trip Options for "<<cName1<<" ---> "<< cName2<<" :"<<endl;

    //direct route condition
    if(G.isGroute(c1,c2)){
        cout<<"Direct Option: "<<cName1<<" ---> EE"<<c1/10<<c1%10<<c2/10<<c2%10<<" ---> "<<cName2<<" for "<<G.getTicketPrice(c1,c2)<<endl;
    }

    //1-stop
    int i=0;
    for(i=1;i<mSize+1;i++){
        if(G.isGroute(c1,i)&& G.isGroute(i,c2)){
            cName3=G.searchGcity(i);
            cout<<"1-Stop Option: "<<cName1<<" ---> EE"<<c1/10<<c1%10<<i/10<<i%10<<" ---> ";
            cout<<cName3<<" ---> EE"<<i/10<<i%10<<c2/10<<c2%10<<" ---> "<<cName2<<" for ";
            cout<<G.getTicketPrice(c1,i)<<" + "<<G.getTicketPrice(i,c2)<<endl;
        }
    }

    //2-stop // all possibilities covered with nested for loop
    int j=0;
    for(i=1;i<mSize+1;i++)
        for(j=1;j<mSize+1;j++)
            if(c1!=j&&c2!=i&&G.isGroute(c1,i)&& G.isGroute(j,c2)&&G.isGroute(i,j)){
                cName3=G.searchGcity(i);
                cName4=G.searchGcity(j);
                cout<<"2-Stop Option: "<<cName1<<" ---> EE"<<c1/10<<c1%10<<i/10<<i%10<<" ---> ";
                cout<<cName3<<" ---> EE"<<i/10<<i%10<<j/10<<j%10<<" ---> "<<cName4<<" ---> EE";
                cout<<j/10<<j%10<<c2/10<<c2%10<<" ---> "<<cName2;
                cout<<" for "<<G.getTicketPrice(c1,i)<<" + "<<G.getTicketPrice(i,j)<<" + "<<G.getTicketPrice(j,c2)<<endl;
    }


cout<<endl<<endl;


};
