void Swap(int& a, int& b);

//BubbleSort Algorithm
stats BubbleSort(int* Arr, int Size,stats &S){

    S.start();
    int i,j;
    int LEI;//last exchanged index

    i=Size-1;
    while(i>0){
        LEI=0;
        for(j =0;j <i;j++){
            S.Icomps();
            if(Arr[j+1]<Arr[j]){
                S.Imoves();
                Swap(Arr[j],Arr[j+1]);
                LEI=j;
            }
        }
    i=LEI;
    }
    S.stop();
    return S;
}

//swap function
void Swap(int& a, int& b){

    int temp;
    temp=a;
    a=b;
    b=temp;

}
