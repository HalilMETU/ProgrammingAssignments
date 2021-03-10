//Hash Function returns -1 for invalid TC IDs

int HashFunctions(long long int TC, int FUNC, int& Size){

if(TC<10000000000 || TC>99999999999 ){//Validation is done here
    return -1;
    }
else{
    switch(FUNC){

    case 1://Folding
        return (TC/(100000000)%1000+(TC/(100000))%1000+(TC/(100))%1000+TC%100)%Size;

    case 2://Middle Squaring

        return (((TC/10000)%1000)*((TC/10000)%1000))%Size;

    case 3://Truncation

        return  TC%Size;

}
return -1;//-1 for invalid FUNC value (has to be  1 || 2 || 3 )
}
}
