//graph data structure for storing routes
class Routes{


private:

    int nV, nE;//number of vertexes and edges
    int mM[mSize][mSize];//adjacency matrix
    string mCities[mSize]; //holds city names

    void setEdge(int &v1, int &v2, int &wt); // set edge with weight wt
    void delEdge(int &v1, int &v2); // delete edge
    bool isEdge(int &v1, int &v2); // is (v1,vj) an edge?
    int weight(int &v1, int &v2); // get the weight of (v1,v2)

    void clearVertex(int v);// clears all edges related to v
    void CtrlInput(int &a);// //if a numerical input is out of range then it is converted to a valid input such as 22->2 or -1->19


public:

    //Constructor
    Routes();
    //~Routes();//No dynamic elements

    void addGcity(int i)const;//to add the city corresponding to i
    void removeGcity(int i);//clears all connections of the vertex i
    string searchGcity(int i);//returns corresponding city name
    void addGroute(int c1, int c2, int w, int cond);//sets an edge(c1,c2) with given weight
    void removeGroute(int c1, int c2);//removes route (c1,c2)
    int searchGroute(int c1, int c2);//RETurns weight of edge (c1,c2)
    void setTicketPrice(int c1, int c2, int w);//edits weight of edge (c1,c2)
    int getTicketPrice(int c1, int c2);//RETurns weight of edge (c1,c2)
    bool isGroute(int c1, int c2); //checks if c1->c2 is a route

    // METHODS WITH string inputs
    void addGcity(string cNmame)const;//to add the city corresponding to City Name
    void removeGcity(string Cname);//clears all the weights associated to Vertex v
    int searchGcity(string cName);//returns weight of the edge
    void addGroute(string cName1, string cName2, int& w, int cond);//adds edge with given weight and condition
    void removeGroute(string cName1, string cName2);//removes weight related to the edge
    int searchGroute(string cName1, string cName2);//returns weigth
    void setTicketPrice(string cName1, string cName2, int& w);//edits weight
    int getTicketPrice(string cName1, string cName2);//returns weight


    void ListGroutes() const;//displays all the active Routes

};


Routes::Routes(){

    nV=mSize;
    int i=0;
    nE= 0;
    //loading cities string array
    string line;
    ifstream myfile("citylist.txt");
    if (myfile.is_open()){
        while ( getline (myfile,line) ){
            mCities[i]=line;
            i++;
        }
        myfile.close();
    }
    else cout << "Unable to open file";
    // Initialize weights as 0
    for(i=0; i < nV; i++)
        for (int j=0; j < nV; j++){
            mM[i][j] = 0;
        }
    }

//if a numerical input is out of range then it is converted to a valid input such as 22->2 or -1->19
void Routes::CtrlInput(int &a){
    if(a<0 || a>nV-1){
        cerr<<"Trying to reach a vertex out of limits, request looped back"<<endl;
        a= (a%nV<0) ? a%nV+nV : a%nV;
    }
}

//destroys all connections of an vertex v
void Routes::clearVertex(int v){
int i=0;
for (i=0; i<nV; i++)
    delEdge(i,v);
for (i=0; i<nV; i++)
    delEdge(v,i);

}

// set an edge
void Routes::setEdge(int &v1, int &v2, int& wt) {
    if(wt<=0)
        wt=rand()%99+1;
    if (!isEdge(v1,v2))
        nE++;
    mM[v1][v2] = wt;
}

//  removes an edge
void Routes::delEdge(int &v1, int &v2) { // Delete edge (v1, v2)
    if (mM[v1][v2] != 0)
        nE--;
    mM[v1][v2] = 0;
}

//questions if the edge exists
bool Routes::isEdge(int &i, int &j){ // Is (v1,v2) an edge?
    return mM[i][j] != 0;
}

//returns weight related to the edge
int Routes::weight(int &v1, int &v2){ // Return weight of (v1,v2)
    return mM[v1][v2];
}



//PUBLIC METHODS
//all methods have includes a control method which checks the input illegitimacy
// other than that their operations are summarized with the private method names.
//NUMERICAL INPUT

//same with isEdge method
bool Routes::isGroute(int c1, int c2){
    c1--;c2--;
    CtrlInput(c1);CtrlInput(c2);
    return isEdge(c1,c2);

}

//Empty method//Assumed the maximum number of cities is same with the size of "citylist.txt" and didn't use the dynamic memory allocation
void Routes::addGcity(int i)const{
//left empty because in this implementation it is not necessary to implement this method
}

//clearVertex
void Routes::removeGcity(int i){
    i--;
    CtrlInput(i);
    clearVertex(i);
}

//city name corresponding to the i is returned
string Routes::searchGcity(int i){
    i--;
    CtrlInput(i);
    return mCities[i];
}

//setEdge
void Routes::addGroute(int c1, int c2, int w, int cond){//Adds route
    c1--;c2--;
    CtrlInput(c1);CtrlInput(c2);
    setEdge(c1,c2,w);
    if(cond==0)
        cout<<"("<<mCities[c1]<<"--->"<<mCities[c2]<<", "<<w<<")"<<endl;
    else
        cout<<"("<<mCities[c1]<<"--->"<<mCities[c2]<<", "<<w<<") Route Added"<<endl;

}

//delEdge
void Routes::removeGroute(int c1, int c2){
    c1--;c2--;
    CtrlInput(c1);CtrlInput(c2);
    delEdge(c1,c2);
    cout<<"("<<mCities[c1]<<"--->"<<mCities[c2]<<") Route Discarded"<<endl;

}

//weight
int Routes::searchGroute(int c1, int c2){
    c1--;c2--;
    CtrlInput(c1);CtrlInput(c2);
    return weight(c1,c2);

}

//setedge
void Routes::setTicketPrice(int c1, int c2, int w){
    c1--;c2--;
    CtrlInput(c1);CtrlInput(c2);
    setEdge(c1,c2,w);
    cout<<"("<<mCities[c1]<<"--->"<<mCities[c2]<<", "<<w<<") is 50% Off"<<endl;
}

//weight
int Routes::getTicketPrice(int c1, int c2){
    c1--;c2--;
    CtrlInput(c1);CtrlInput(c2);
    return weight(c1,c2);

}


//PUBLIC METHODS
//Input conversion is done using int Routes::searchGcity(string cName)
//methods are explained in methods with int inputs
//STRING INPUT

void Routes::addGcity(string cNmame)const{
//left empty because in this implementation it is not necessary to implement this method
}

void Routes::removeGcity(string Cname){

    clearVertex(searchGcity(Cname));

}

//using string array and compare method from string library int is extracted.
int Routes::searchGcity(string cName){

    for(int i=0 ; i<nV ; i++)
        if(cName.compare(mCities[i])==0)
            return i+1;
    return nV+1;

}

void Routes::addGroute(string cName1, string cName2, int& w, int cond){

    int c1=searchGcity(cName1)-1;
    int c2=searchGcity(cName2)-1;
    setEdge(c1,c2,w);
    if(cond==0)
        cout<<"("<<mCities[c1]<<"--->"<<mCities[c2]<<", "<<w<<")"<<endl;
    else
        cout<<"("<<mCities[c1]<<"--->"<<mCities[c2]<<", "<<w<<") Route Added"<<endl;
}

void Routes::removeGroute(string cName1, string cName2){

    int c1=searchGcity(cName1)-1;
    int c2=searchGcity(cName2)-1;
    CtrlInput(c1);CtrlInput(c2);
    delEdge(c1,c2);
    cout<<"("<<mCities[c1]<<"--->"<<mCities[c2]<<") Route Discarded"<<endl;
}

int Routes::searchGroute(string cName1, string cName2){

    int c1=searchGcity(cName1)-1;
    int c2=searchGcity(cName2)-1;
    CtrlInput(c1);CtrlInput(c2);
    return weight(c1,c2);

}

void Routes::setTicketPrice(string cName1, string cName2, int& w){
    int c1=searchGcity(cName1)-1;
    int c2=searchGcity(cName2)-1;
    CtrlInput(c1);CtrlInput(c2);
    setEdge(c1,c2,w);
    cout<<"("<<mCities[c1]<<"--->"<<mCities[c2]<<", "<<w<<") is 50% Off"<<endl;
}

int Routes::getTicketPrice(string cName1, string cName2){

    int c1=searchGcity(cName1)-1;
    int c2=searchGcity(cName2)-1;
    CtrlInput(c1);CtrlInput(c2);

    return weight(c1,c2);

}



//DISPLAY METHOD
void Routes::ListGroutes() const{
cout<<"Routes:"<<endl;
    for(int i=0;i<nV;i++)
        for(int j=0;j<nV;j++)
            if(mM[i][j] != 0)
                cout<<"("<<mCities[i]<<"--->"<<mCities[j]<<", "<<mM[i][j]<<")"<<endl;

cout<<endl<<endl;
}
