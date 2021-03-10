void UI(){

HT Table;
int C1=1;
int S1=-1;
int N=0;
int Method=0;
bool init=false;//keeps initialization state
long long int reader;//used to read from file
long long int Input=0;

while(C1==1){//infinite loop can be broken from Command prompt by '0' input

    Input=0;
    S1=-1;

    //Table entries

    cout<<"1. Initialize Hash Table                 ";
    if(!init)
        cout<<"Not Initialized"<<endl;
    else
        cout<<"Initialization Complete"<<endl;

    cout<<"2. Load T.C. ID Numbers from file        ";
    if(!init)
        cout<<"Initialization Required"<<endl;
    else
        cout<<"Ready To Use"<<endl;


    cout<<"3. Add new T.C. ID Number                ";
    if(!init)
        cout<<"Initialization Required"<<endl;
    else
        cout<<"Ready To Use"<<endl;


    cout<<"4. Delete a T.C. ID Number               ";
    if(!init)
        cout<<"Initialization Required"<<endl;
    else
        cout<<"Ready To Use"<<endl;


    cout<<"5. Search for a T.C. ID Number           ";
    if(!init)
        cout<<"Initialization Required"<<endl;
    else
        cout<<"Ready To Use"<<endl;


    cout<<"6. Print out Hash Table                  ";
    if(!init)
        cout<<"Initialization Required"<<endl;
    else
        cout<<"Ready To Use"<<endl;


    cout<<"0. Quit the Program"<<endl;

    //Input1
    cout<<"Select an item from the menu: ";
    cin>>S1;

    //User options

    //Exits UI
    if(S1==0)
        C1=0;

    //initialization
    if(S1==1 && !init){
            //loop will continue till a valid input is received
        while(N<=0){
            cout<<"Enter size: ";
            cin>>N;
        }

        Method=0;//loop will continue till a valid input is received
        while(Method<1 || Method>3){
            cout<<"1. Folding"<<endl;
            cout<<"2. Middle Squaring"<<endl;
            cout<<"3. Truncation"<<endl;
            cout<<"Select a Hash Function: ";
            cin>>Method;
        }
    init=true;//initialization state is changed
    Table.setHT(N,Method);//Dynamic elements of the already initialized Table is set.
    }

    //Loads from File
    if(S1==2 && init){
    //loader function
    ifstream myfile("hash_table_init.txt");
    if (myfile.is_open()){
        while ( myfile>> reader){
            Table.ins(reader);
        }
        myfile.close();
    }
    else cout << "Unable to open file";
    }

    //Manual Entry Option
    if( S1==3 && init ){
        cout<<"Enter TC ID Number for Insertion: ";
        cin>>Input;
        cout<<"Insertion was";
        if(!Table.ins(Input))
            cout<<" not";
        cout<<" succesful"<<endl;
    }

    //Manual Deletion Option
    if( S1==4 && init ){
        cout<<"Enter TC ID Number for Deletion: ";
        cin>>Input;
        cout<<"Deletion was";
        if(!Table.del(Input))
            cout<<" not";
        cout<<" succesful"<<endl;
    }

    //Manual Search Option
    if( S1==5 && init ){
        cout<<"Enter TC ID Number for Search: ";
        cin>>Input;
        cout<<"TC ID was";
        if(!Table.seek(Input))
            cout<<" not";
        cout<<" found"<<endl;
    }

    //display option
    if( S1==6 && init ){
        Table.display();
    }

    cout<<endl<<endl<<endl;

}

return;
}
