class FTr;
class node{//node class for BST
    friend class FTr;
    protected:
        node* left;
        node* right;
        bool deleted;//indicates removed node

    public:
        int data;//flight info
        int OccupancyState;//occupancy info
        node(){
            //not deleted
            //created with random occupancy rate
            deleted=false;
            OccupancyState=rand()%99+1;
            }

};


