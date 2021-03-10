//Linked List Class
class HT;
class LL{
friend class HT;
private:
    node* head;
    void pop();//pops the item in top

public:


    //constructor && destructor
    LL(){ head=NULL;}//start with a NULL head poiter
    ~LL(){ while(!Empty()) pop();}

    bool seek(long long int item)const;//checks the list for the given item
    bool push(long long int TC);//inserts the TC number
    bool delitem(long long int &item);//deletes the given item if it exists



    Empty(){ return head==NULL;}

};
//Insertion method
bool LL::push(long long int TC){

    if(seek(TC)){
        node* temp=new node;
        temp->data=TC;
        temp->link=head;
        head=temp;
        return true;
    }
    else
        return false;

}
//deletion method
void LL::pop(){
    if (Empty())
        return;
    node* ptr=head;
    head=ptr->link;
    delete ptr;
        return;
}

//uses pop method to delete
//if item is not pointed by head
//then the item is carried to top
bool LL::delitem(long long int& item){
    if(head==NULL)
        return false;//if list is empty
    else{
        if (head->data==item){
            pop();
            return true;//if sought item is the first element in the list
            }
        else{
            node* temp=head;
            node* temp2;
            while (temp->link!=NULL){
                if(temp->link->data==item){//checking ahead of the list
                    temp2=temp->link;
                    temp->link=temp2->link;
                    delete temp2;
                    return true;//item is found in the list
                }
            temp=temp->link;//iteration
            }
            return false;//item was not found
        }
    }
}
//searching method
bool LL::seek(long long int item)const{

    node* temp=head;
    while (temp!=NULL){
        if(temp->data==item){
            return false;
        }
    temp=temp->link;
    }
    return true;

}
