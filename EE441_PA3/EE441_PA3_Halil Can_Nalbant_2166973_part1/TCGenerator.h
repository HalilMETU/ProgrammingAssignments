// Function generates TC number according to its rules
long long int TCIDGen(){
short int d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11;

//randomly generated digits
d1=rand()%9+1;//1-9
d2=rand()%10;//0-9
d3=rand()%10;
d4=rand()%10;//...
d5=rand()%10;
d6=rand()%10;
d7=rand()%10;
d8=rand()%10;
d9=rand()%10;//0-9


//Found the relation from https://www.simlict.com/
d10=( (d1 + d3 + d5 + d7 + d9) * 7 - (d2 + d4 + d6 + d8) )%10;
d11=( d1 + d2 + d3 + d4 + d5 + d6 + d7 + d8 + d9 + d10 )%10;

//Output constructed
long long int X;
X=d1;
X=d2+X*10;
X=d3+X*10;
X=d4+X*10;
X=d5+X*10;
X=d6+X*10;
X=d7+X*10;
X=d8+X*10;
X=d9+X*10;
X=d10+X*10;
X=d11+X*10;

return X;
}
