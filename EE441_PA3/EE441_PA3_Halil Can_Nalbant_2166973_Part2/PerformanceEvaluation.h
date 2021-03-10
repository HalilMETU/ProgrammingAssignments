void randomArray(int* A, int &N);
void copyArray(int* A, int *B, int& N);

void PEval(int *Size,int M){
    stats S1,S2,S3,S4,S5,S6,S7,S8,S9,S10;
    int j,k,r1(0),r2(0);
    int *A,*B;
    for(int i=0;i<M;i++){
        int N=Size[i];
        A=new int[N];//random array is assigned to this one
        B=new int[N];//A[] is copied to B[]
        r1=r2=0;
        cout<<"Array Size: "<<N<<endl<<endl;
        for(j=0;j<5;j++){
            randomArray(A,N);

            for(k=-1;k<10000/N;k++){
                copyArray(A,B,N);
                BubbleSort(B,N,S1);
                r1++;//how many times sorting algorithm was runned for selection, bubble, and insertion sort
            }
            for(k=-1;k<10000/N;k++){
                copyArray(A,B,N);
                SelectionSort(B,N,S2);
            }
            for(k=-1;k<10000/N;k++){
                copyArray(A,B,N);
                InsertionSort(B,N,S9);
            }
            for(k=-1;k<25000/N;k++){
                copyArray(A,B,N);
                S3.start();
                QuickSort1(B,0,N-1,S3);
                S3.stop();
                r2++;//how many times the sorting algorithm runned for QuickSort and CustomSort
            }
            for(k=-1;k<25000/N;k++){
                copyArray(A,B,N);
                S4.start();
                QuickSort2(B,0,N-1,S4);
                S4.stop();
            }
            for(k=-1;k<25000/N;k++){
                copyArray(A,B,N);
                S5.start();
                QuickSort3(B,0,N-1,S5);
                S5.stop();
            }
            for(k=-1;k<25000/N;k++){
                copyArray(A,B,N);
                S6.start();
                QuickSort4(B,0,N-1,S6);
                S6.stop();
            }
            for(k=-1;k<25000/N;k++){
                copyArray(A,B,N);
                S10.start();
                QuickSort5(B,0,N-1,S10);
                S10.stop();
            }
            for(k=-1;k<25000/N;k++){
                copyArray(A,B,N);
                S7.start();
                CustomSort(B,0,N-1,S7);
                S7.stop();
            }
            for(k=-1;k<25000/N;k++){
                copyArray(A,B,N);
                S8.start();
                CustomSort2(B,0,N-1,S8);
                S8.stop();
            }
        }
            cout<<"BubbleSort:    ";
            S1.display(r1);
            cout<<"SelectionSort  ";
            S2.display(r1);
            cout<<"InsertionSort  ";
            S9.display(r1);
            cout<<"QuickSort1      ";
            S3.display(r2);
            cout<<"QuickSort2      ";
            S4.display(r2);
            cout<<"QuickSort3      ";
            S5.display(r2);
            cout<<"QuickSort4      ";
            S6.display(r2);
            cout<<"QuickSort5      ";
            S10.display(r2);
            cout<<"CustomSort      ";
            S7.display(r2);
            cout<<"CustomSort2     ";
            S8.display(r2);
            cout<<endl<<endl;

        delete []A;
        delete []B;
    }
}


//randomArray
void randomArray(int* A, int &N){
    for(int i=0;i<N;i++)
        A[i]=(rand()*32767+rand())%(10*N);//rand()*32767+rand() generates 1bil-0 with equal probability
}
//copy array
void copyArray(int* A, int *B, int& N){
    for(int i=0;i<N;i++)
        B[i]=A[i];
}
