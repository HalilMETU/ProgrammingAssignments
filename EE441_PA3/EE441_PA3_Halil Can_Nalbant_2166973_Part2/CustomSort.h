//Custom Sort
//mix of QuickSort1 and Insertion Sort

//Custom Sort2
//mix of QuickSort5 and Insertion Sort
//QuickSort 5-> median of 3 but not random like QuickSort4
//it compares low high and (high+low)/2
//saving computation time of rand();

void CustomSort(int *Arr,int l,int h, stats &S)
{
//implementation nearly same with the classnotes
    int p;
    if(l<h){
        int SU=l+1;
        int SD=h;
        p=Arr[l];
        while(true){
            while(SU<h+1 && Arr[SU]<=p){//without SU<h+1 comparison errors occur
                S.Icomps();
                SU++;}
            while(l-1<SD && Arr[SD]>p){
                SD--;
                S.Icomps();
                }
            if(SU<SD){
                S.Imoves();
                Swap(Arr[SD],Arr[SU]);
            }
            else
                break;
        }
        S.Imoves();
        Swap(Arr[SD],Arr[l]);
        if(SD-l-1<Treshold){//if threshold is reached switch to insertion sort
            S.stop();
            InsertionSort(Arr+l,SD-l,S);
            S.start();
            }
        else//else keep going
            CustomSort(Arr,l,SD-1,S);
        if(h-SD-1<Treshold){
            S.stop();
            InsertionSort(Arr+SD+1,h-SD,S);
            S.start();
            }
        else
            CustomSort(Arr,SD+1,h,S);
    }



}

void CustomSort2(int *Arr,int l,int h, stats &S)
{

    int p;
    if(l<h){
        int SU=l+1;
        int SD=h;
        int mid=(h+l)/2;
        Median(Arr,l,l,mid,h,S);
        p=Arr[l];
        while(true){
            while(SU<h+1 && Arr[SU]<=p){
                S.Icomps();
                SU++;}
            while(l-1<SD && Arr[SD]>p){
                SD--;
                S.Icomps();
                }
            if(SU<SD){
                S.Imoves();
                Swap(Arr[SD],Arr[SU]);
            }
            else
                break;
        }
        S.Imoves();
        Swap(Arr[SD],Arr[l]);
        if(SD-l-1<Treshold){//if threshold is reached switch to insertion sort
            S.stop();
            InsertionSort(Arr+l,SD-l,S);
            S.start();
            }
        else//else keep going
            CustomSort2(Arr,l,SD-1,S);
        if(h-SD-1<Treshold){
            S.stop();
            InsertionSort(Arr+SD+1,h-SD,S);
            S.start();
            }
        else
            CustomSort2(Arr,SD+1,h,S);
    }



}
