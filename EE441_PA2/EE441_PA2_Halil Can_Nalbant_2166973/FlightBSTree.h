
class FTr{

private:
    node* root;//only pointer to root node is stored


    node* clearall(node* r);//deletes child and pointed nodes
    node* ins(int &x, node* ptr);//inserts node to the tree
    void inorder(node* t);//displays BST data using in-order algorithm
    node* seek(node* ptr, int &x)const;//search x in BST then returns pointer to node

    //marks the node as deleted.//instead of deallocating on each time a node is deleted
    //nodes are deleted only when destructor is called
    void delnode(int &x, node* t);

    //randomly assigns Occupancy states to all of the BST nodes
    void randomOCS(node* t,int &rdm);
    //nodes which contain occupancy rate lower than the threshold are stored in List
    void getLowOS(node* t,FlightStack &List)const;

public:
    //cons & decons
    FTr();
    ~FTr();

    //Varios methods defined in the assignment with self-explanatory names
    void ADDTFLIGHT(int data,int cond);//inserts node with the given data
    void REMOVETFLIGHT(int data);//marks the node as deleted
    node* SEARCHTFLIGHT(int data)const;//searchs for given data in BST
    void setOccupancyState(int data,int OCS);//sets Occupancy rate for given data
    int getOccupancyState(int data)const;//returns Occupancy rate information of given data

    //node* ROOT(){return root;}

    void randomOCS();//randomly assigns Occupancy states to all of the BST nodes
    void display();//displays all the available flights

    void getLowOS(FlightStack &List)const;//flights with low occupancy state are stored in the List
};
//constructor
FTr::FTr(){

    root=NULL;

}
//deconstructor
FTr::~FTr(){

    root=clearall(root);

}
//mothod for deallocating memory allocated by BST
node* FTr::clearall(node* r) {//deletes child and pointed nodes

    if(r == NULL)
        return NULL;
    {
    clearall(r->left);
    clearall(r->right);
    delete r;
    }
    return NULL;
}
//inserts the given data in the BST
node* FTr::ins(int &x, node* ptr){//inserts node to the tree

    if(ptr == NULL)//means the data is not found in the BST
    {
        ptr = new node;
        ptr->data = x;
        ptr->left = ptr->right = NULL;
        ptr->deleted=false;
    }
    else if(x < ptr->data)
        ptr->left = ins(x, ptr->left);
    else if(x > ptr->data)
        ptr->right = ins(x, ptr->right);
    else{//if data==x
        ptr->data = x;
        if(ptr->deleted){//if deleted == true
            ptr->deleted=false;
        }
    }
    return ptr;
}
//displays inorder
void FTr::inorder(node* t) {//displays BST data using in-order algorithm
    if(t == NULL)
        return;
    inorder(t->left);
    if(!(t->deleted)){//display only deleted==false
        cout <<"EE"<< t->data/1000<< (t->data/100)%10<< (t->data/10)%10 <<(t->data)%10<<endl;
    }
    inorder(t->right);
}
//returns a pointer to the node containing the x
node* FTr::seek(node* ptr, int &x)const {//search x in BST then returns pointer to node

    if(ptr == NULL)
        return NULL;
    else if(x < ptr->data)
        return seek(ptr->left, x);
    else if(x > ptr->data)
        return seek(ptr->right, x);
    else{
        if(ptr->deleted)
            return NULL;
        else
            return ptr;
    }
}

//marks the node as deleted if it contains x
 void FTr::delnode(int &x, node* t){//marks the node as deleted.
    if(t == NULL)
        return;
    else if(x < t->data)
        delnode(x, t->left);
    else if(x > t->data){
        delnode(x, t->right);
        }
    if(t->data==x){
        t->deleted=true;
    }
    return;
 }

//inserts flight
void FTr::ADDTFLIGHT(int data,int cond){
    if (cond==0)
        cout <<"EE"<<(data/1000)%10<< (data/100)%10<< (data/10)%10 << (data)%10<<endl;
    else if(cond==1)
        cout <<"Flight EE"<<(data/1000)%10<< (data/100)%10<< (data/10)%10 << (data)%10<<" added"<<endl;
    root=ins(data, root);
}

//marks the flight as deleted
void FTr::REMOVETFLIGHT(int data){
    cout <<"Flight EE"<<(data/1000)%10<< (data/100)%10<< (data/10)%10 << (data)%10<<" Cancelled"<<endl;
    //root=delnode(data,root);
    delnode(data,root);
}

//returns the pointer to the node contains the data
node* FTr::SEARCHTFLIGHT(int data)const {
    return seek(root, data);
}

//edits the OCS of the node containing the data
void FTr::setOccupancyState(int data,int OCS){
    node* temp=seek(root, data);
    if(temp!=NULL){
        temp->OccupancyState=OCS;
    }
}

//returns occupancy info of the node containing the data
int FTr::getOccupancyState(int data)const{
    node* temp=seek(root, data);
    if(temp!=NULL)
        return temp->OccupancyState;
    else
        return -1;
}



//displays all of the flights
void FTr::display(){
    cout<<"Flights:"<<endl;
    inorder(root);
    cout<<endl<<endl;
}

//methods to get the flight list of low occupancy rate flights
void FTr::getLowOS(FlightStack &List)const{
    FlightStack temp;
    getLowOS(root,temp);

    while(!temp.Empty())
        List.Push(temp.Pop());

}

void FTr::getLowOS(node* t,FlightStack &List)const{

    if(t == NULL)
        return;
    getLowOS(t->left,List);
    if(!(t->deleted)&&t->OccupancyState<OSTreshold){
        List.Push(t->data);
        }
    getLowOS(t->right,List);

}


//methods to assign random occupancy rate each month
void FTr::randomOCS(){

    int randomnum;
    randomOCS(root,randomnum);

}

void FTr::randomOCS(node* t,int &rdm){

    if(t == NULL)
        return;
    randomOCS(t->left,rdm);
    if(!(t->deleted)&&t->OccupancyState<OSTreshold){
        rdm=rand()%99+1;
        t->OccupancyState=rdm;}
    randomOCS(t->right,rdm);

}




