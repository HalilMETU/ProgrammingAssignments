void Median(int* &Arr,int &l,int &M1, int& M2, int &M3, stats &S);

//includes QuickSort1 QuickSort2 QuickSort3 QuickSort4 QuickSort5 & Median function

//QS1
//very close to implementation in class notes
//except the recording statistics and corrected errors


//QS2
//swap the middle element with low and apply QS1 algorithm

//QS3
//swap the random element with low and apply QS1 algorithm

//QS4
//after choosing from random element swap with low and apply QS1

//QS5
//after choosing from high, low, (high+low)/2 swap with low and apply QS1


void QuickSort1(int *Arr,int l,int h, stats &S)
{
    int p;
    if(l<h){
        int SU=l+1;
        int SD=h;
        p=Arr[l];
        while(true){
            while(SU<h+1 && Arr[SU]<=p){//move until h or bigger than pivot
                S.Icomps();
                SU++;}
            while(l-1<SD && Arr[SD]>p){//move until l or smaller than pivot
                SD--;
                S.Icomps();
                }
            if(SU<SD){//Stuck
                S.Imoves();
                Swap(Arr[SD],Arr[SU]);
            }
            else
                break;
        }
        S.Imoves();
        Swap(Arr[SD],Arr[l]);
        QuickSort1(Arr,l,SD-1,S);
        QuickSort1(Arr,SD+1,h,S);
    }
}


void QuickSort2(int *Arr,int l,int h, stats &S)
{
    int p;
    if(l<h){
        int SU=l+1;
        int SD=h;
        Swap(Arr[l],Arr[(h+l)/2]);
        S.Imoves();
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
        QuickSort2(Arr,l,SD-1,S);
        QuickSort2(Arr,SD+1,h,S);
    }
}

void QuickSort3(int *Arr,int l,int h, stats &S)
{
    int p;
    if(l<h){
        int SU=l+1;
        int SD=h;
        Swap(Arr[l],Arr[(rand()*32767+rand())%(h-l+1)+l]);
        S.Imoves();
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
        QuickSort3(Arr,l,SD-1,S);
        QuickSort3(Arr,SD+1,h,S);
    }
}

void QuickSort4(int *Arr,int l,int h, stats &S)
{
    int p;
    if(l<h){
        int SU=l+1;
        int SD=h;
        int M1=rand()%(h-l+1)+l;
        int M2=rand()%(h-l+1)+l;
        int M3=rand()%(h-l+1)+l;

        Median(Arr,l,M1,M2,M3,S);
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
        QuickSort4(Arr,l,SD-1,S);
        QuickSort4(Arr,SD+1,h,S);
    }
}
void QuickSort5(int *Arr,int l,int h, stats &S)
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
        QuickSort5(Arr,l,SD-1,S);
        QuickSort5(Arr,SD+1,h,S);
    }
}


void Median(int* &Arr,int &l,int &M1, int& M2, int &M3, stats &S){
        if(Arr[M1]>=Arr[M2]){
            S.Icomps();
            if(Arr[M3]>=Arr[M1]){
                S.Icomps();
                S.Imoves();
                Swap(Arr[l],Arr[M1]);
            }
            else{
                S.Icomps();
                if(Arr[M2]>=Arr[M3]){
                    S.Icomps();
                    S.Imoves();
                    Swap(Arr[l],Arr[M2]);
                }
                else{
                    S.Imoves();
                    S.Icomps();
                    Swap(Arr[l],Arr[M3]);
                }
                }
        }
        else{
            S.Icomps();
            if(Arr[M1]>=Arr[M3]){
                S.Icomps();
                S.Imoves();
                Swap(Arr[l],Arr[M1]);
            }
            else{
                S.Icomps();
                if(Arr[M2]>=Arr[M3]){
                    S.Icomps();
                    S.Imoves();
                    Swap(Arr[l],Arr[M3]);
                }
                else{
                    S.Icomps();
                    S.Imoves();
                    Swap(Arr[l],Arr[M2]);
                }
                }
        }

}
