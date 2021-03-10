//Linked List node
class LL;
class HT;
class node{

friend class LL;
friend class HT;
private:
    node* link;//Link

public:
    long long int data;//contains the TC ID

    node(){link=NULL;}
};
