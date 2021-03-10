void UI(){
int i,j;
stats S;
int C1=1;
int S1=-1;
int S2=-1;
int N=-1;
bool init=false;
int* InputArray;
while (C1==1){
    S1=-1;
    cout<<"1. Initialize Input Array Randomly  "<<endl;
    cout<<"2. Load Input Array From a File     "<<endl;
    cout<<"3. Perform Bubble Sort              "<<endl;
    cout<<"4. Perform Quick Sort               "<<endl;
    cout<<"5. Perform Selection Sort           "<<endl;
    cout<<"6. Perform Your Own Sort            "<<endl;
    cout<<"7. Compare Sorting Algorithms       "<<endl;
    //cout<<"99. Performance Evaluation           "<<endl;
    cout<<"0. Exit The Program"<<endl<<endl<<endl;
    cout<<"Please Choose an Item From The Menu ";
    cin>>S1;


    /////////////////////////////////////////////////
    /////////////00000000000000000////////////////////
    /////////////////////////////////////////////////
    if (S1==0){
        if(init)
            delete []InputArray;
        return;}
/////////////////////////////////////////////////
/////////////////111111111111////////////////////
/////////////////////////////////////////////////

    if (S1==1){
        N=-1;
        if(init)
            delete []InputArray;
        else
            init=true;
        while(N<=0){
        cout<<"Please enter the size of the Random Array: ";
        cin>>N;
        if(N>0){
            N=N%25001;
            InputArray=new int[N];
            randomArray(InputArray, N);
        }
        else
            cout<<"Not Valid"<<endl;
        }

    //initialize the random array
    cout<<"Random Array of Size "<<N<<" is initialized"<<endl;
    }
    /////////////////////////////////////////////////
    ///////////////////222222222/////////////////////
    /////////////////////////////////////////////////
    if (S1==2){
        N=-1;
    if(init)
        delete []InputArray;
    else
        init=true;
    while(N<=0){
        cout<<"Please enter the size of the Random Array: ";
        cin>>N;
        if(N>0){
            N=N%25001;
            InputArray=new int[N];
        Loader(InputArray,N);
                }
        else
            cout<<"Not Valid"<<endl;
        }
    cout<<"Array Loaded"<<endl;
    }
    /////////////////////////////////////////////////
    ////////////////33333333333//////////////////////
    /////////////////////////////////////////////////
    if(S1==3 && init){
        //BubbleSort
        BubbleSort(InputArray,N,S);
        //display sorted array
        for(i=0;i<N;i++)
            cout<<InputArray[i]<<endl;
    }
    /////////////////////////////////////////////////
    /////////////////44444444444////////////////////
    /////////////////////////////////////////////////
    if(S1==4 && init){
        //QuickSort
        S2=-1;
        cout<<"1. Quick Sort-1 (select first element as pivot)"<<endl;
        cout<<"2. Quick Sort-2 (select middle element as pivot)"<<endl;
        cout<<"3. Quick Sort-3 (select randomly chosen element of the array as pivot)"<<endl;
        cout<<"4. Quick Sort-4 (select the median of 3 randomly chosen elements of the array as pivot)"<<endl<<endl;
        while(S2<1 || S2>4){
            cout<<"Please Select an item from the menu: ";
            cin>>S2;
        }
        if(S2==1){
            QuickSort1(InputArray,0,N-1,S);//QS1
            for(i=0;i<N;i++)//display
                cout<<InputArray[i]<<endl;
        }
        if(S2==2){
            QuickSort2(InputArray,0,N-1,S);//QS2
            for(i=0;i<N;i++)//display
                cout<<InputArray[i]<<endl;
        }
        if(S2==3){
            QuickSort3(InputArray,0,N-1,S);//QS3
            for(i=0;i<N;i++)//display
                cout<<InputArray[i]<<endl;
        }
        if(S2==4){
            QuickSort4(InputArray,0,N-1,S);//QS4
            for(i=0;i<N;i++)//display
                cout<<InputArray[i]<<endl;
        }


    }
    /////////////////////////////////////////////////
    /////////////////////55555///////////////////////
    /////////////////////////////////////////////////
    if(S1==5 && init){
        //SelectionSort
        SelectionSort(InputArray,N,S);
        for(i=0;i<N;i++)//display
            cout<<InputArray[i]<<endl;
    }
    /////////////////////////////////////////////////
    ////////////////////66666666//////////////////////
    /////////////////////////////////////////////////
    if(S1==6 && init){
        //MySort
        CustomSort2(InputArray,0,N-1,S);
        for(i=0;i<N;i++)//display
            cout<<InputArray[i]<<endl;
    }
    /////////////////////////////////////////////////
    ////////////////777777777777777////////////////
    //Using the Input Array all algorithms evaluated
    /////////////////////////////////////////////////
    if(S1==7 && init){
        cout<<"Array Size: "<<N<<endl<<endl;
        cout<<"Algorithm     #comparisons      #moves      time(msec)"<<endl;
        int* A1=new int[N];


        S.Reset();
        cout<<"BubbleSort:    ";
        for(j=0;j<25000/N;j++){//Need to repeat the sorting to get non-zero time for low array sizes
            copyArray(InputArray,A1,N);//copy array
            BubbleSort(A1,N,S);
        }
        S.display(25000/N);

        S.Reset();
        cout<<"SelectionSort  ";
        for(j=0;j<25000/N;j++){
            copyArray(InputArray,A1,N);
            SelectionSort(A1,N,S);
        }
        S.display(25000/N);

        S.Reset();
        cout<<"QuickSort1      ";
        for(j=0;j<100000/N;j++){
            copyArray(InputArray,A1,N);
            S.start();
            QuickSort1(A1,0,N-1,S);
            S.stop();
        }
        S.display(100000/N);

        S.Reset();
        cout<<"QuickSort2      ";
        for(j=0;j<100000/N;j++){
            copyArray(InputArray,A1,N);
            S.start();
            QuickSort2(A1,0,N-1,S);
            S.stop();
        }
        S.display(100000/N);

        S.Reset();
        cout<<"QuickSort3      ";
        for(j=0;j<100000/N;j++){
            copyArray(InputArray,A1,N);
            S.start();
            QuickSort3(A1,0,N-1,S);
            S.stop();
        }
        S.display(100000/N);

        S.Reset();
        cout<<"QuickSort4      ";
        for(j=0;j<100000/N;j++){
            copyArray(InputArray,A1,N);
            S.start();
            QuickSort4(A1,0,N-1,S);
            S.stop();
        }
        S.display(100000/N);


        S.Reset();
        cout<<"CustomSort2     ";
        for(j=0;j<100000/N;j++){
            copyArray(InputArray,A1,N);
            S.start();
            CustomSort2(A1,0,N-1,S);
            S.stop();
        }
        S.display(100000/N);

        delete []A1;
    }

    /////////////////////////////////////////////////
    //////////////////99/////////////////////
    //Performance Evaluation ///////////////////////////
    /////////////////////////////////////////////////
    if(S1==99){
        //Performance Evaluation
        int M=5;
        int Size[M]={100,1000,5000,10000,25000};
        //int M=12;
        //int Size[M]={3,7,10,20,25,35,45,55,75,85,100,120};//to see how algorithms dealth with low array sizes
        PEval(Size,M);
    }
    cout<<endl<<endl;
}
return;
}
