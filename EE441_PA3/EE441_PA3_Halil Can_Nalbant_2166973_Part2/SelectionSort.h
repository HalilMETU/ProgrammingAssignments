//Selection Sort
//Insertion Sort


//similar to the implementation in class notes
void SelectionSort(int* Arr, int Size,stats &S){

    S.start();//start the timer

    int SI,i,j;//Small index,i,j

    for(i =0;i<Size-1;i++){
        SI=i;
        for(j =i+1;j <Size;j++){
            S.Icomps();//increment comparisons
            if(Arr[j]<Arr[SI]){
                SI=j;
                }
        }
        S.Imoves();//increment moves
        Swap(Arr[i],Arr[SI]);
    }

    S.stop();//stop the timer
    return;
}

//insertion sort added to use with CustomSort

void InsertionSort(int* Arr, int Size,stats &S){
    S.start();

    int i, key, j;
    for (i = 1; i < Size; i++)
    {
        key = Arr[i];
        j = i - 1;

        while (j >= 0 && Arr[j] > key)
        {
            S.Icomps();
            S.Imoves();
            Arr[j + 1] = Arr[j];
            j = j - 1;
        }
        Arr[j + 1] = key;
    }


    S.stop();
}
