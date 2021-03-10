
//simple linked list stack class
class FlightStack{

private:
    node2* head;

public:
    //constructor
    FlightStack(){
        head=NULL;
        }
    //deconstructor
    ~FlightStack(){
        while(!Empty())
        Pop();
    }
    //empty method
    Empty(){ return head==NULL;}
    //push method
    void Push(int Data){
        node2* temp=new node2;
        temp->data=Data;
        temp->right=head;
        head=temp;
    }
    //pop method
    int Pop(){
        if (Empty())
            return -1;
        int temp=head->data;
        node2* ptr=head;
        head=ptr->right;
        delete ptr;

        return temp;
    }

};

