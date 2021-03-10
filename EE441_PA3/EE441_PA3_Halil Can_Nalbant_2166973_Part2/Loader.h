
void Loader(int* InputArray,int &N){
    int reader;//lines are precorded to this parameter
    ifstream myfile("input_array.txt");//predefined text file name
    if (myfile.is_open()){//opening file
        for(int i=0;i<N && myfile>> reader;i++){//iterating thru until N or End of document is reached
            InputArray[i]=reader;//recording the lines
        }
        myfile.close();//closing the file
    }
    else cout << "Unable to open file";//error opening the document
}
