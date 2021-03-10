class HT{
private:

    LL** mTable;//pointer to the array of pointers to LinkedList obj
    int mSize;//size determined after construction by setHT method
    int FuncType;//Type of hash function

public:
    void setHT(int n,int Type);//sets up the dynamic memory
    HT();
    ~HT();

    bool ins(long long int item);
    bool del(long long int item);
    bool seek(long long int item);

    void display()const;
    float Full();

};

HT::HT(){//initial values are set such that the accessing methods before using setHT won't broke the program
mSize=-1;
FuncType=-1;
}


//dynamic allocation
void HT::setHT(int n,int Type){
if (mSize==-1 && n>0 && Type<4 && Type>0){
    mSize=n;
    FuncType=Type;
    mTable=new LL*[mSize];
    for(n=0;n<mSize;n++)
        *(mTable+n)=NULL;
}
}

//destructor
HT::~HT(){
if(mSize!=-1){
    for(int i=0;i<mSize;i++)
        delete mTable[i];
    delete []mTable;
}
}

//insertion operation
bool HT::ins(long long int item){
    int i=HashFunctions(item,FuncType,mSize);
    if(i<0)
        return false;

    if(mTable[i]==NULL)
        mTable[i]=new LL;

    return mTable[i]->push(item);//push method handles already existing IDs before insertion

}

//deletion operation
bool HT::del(long long int item){

    int i=HashFunctions(item,FuncType,mSize);

    if(i<0 || mTable[i]==NULL)
        return false;


    return mTable[i]->delitem(item);//again LinkedList method handles necessary operations

}

//Search returns bool type also makes sure that the dynamic memory was not reached
bool HT::seek(long long int item){

    int i=HashFunctions(item,FuncType,mSize);

    if(i<0 || mTable[i]==NULL)
        return false;

    return !(mTable[i]->seek(item));
}

//display
void HT::display()const{
    if(mSize!=-1){
    int i;

    //stores the link fields of the nodes, when there are "MoreThanOne(MTO)" node in a Linked list
    //to access them later and print them after the Nth entry of the HashTable
    node* MTO[mSize];


    for(i=0;i<mSize;i++){
        MTO[i]=NULL;//NULL is assigned initially
        cout<<i<<". ";
        if(mTable[i]==NULL)//never allocated
            cout<<"E"<<endl;
        else{
            if(mTable[i]->Empty())
                cout<<"D"<<endl;//allocated but then there are no entries left in the bucket
            else{//At least one item is in the Linked list
                MTO[i]=mTable[i]->head;//gets NULL or pointer to a node
                cout<<MTO[i]->data<<endl;
                MTO[i]=MTO[i]->link;
            }
        }
    }

    //Collided Entries are printed
    int j=mSize-1;
    for(i=0;i<mSize;i++)//for every bucket of the list
        while(MTO[i]!=NULL){//until the end of each list is reached
            j++;
            cout<<j<<". ";
            cout<<MTO[i]->data<<endl;//print data
            MTO[i]=MTO[i]->link;//iterate
    }



    }
}

//Does not consider deleted entries
float HT::Full(){
    float c=0;

    for(int i=0;i<mSize;i++)
        if(mTable[i]!=NULL)//condition for deleted entries can be add here
            c++;
    return c/mSize;

}

