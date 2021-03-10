//Performance Evaluation Function
//Inserting 200 unique TC ID
void PEval(){

HT C1,C2,C3;
C1.setHT(100,1);
C2.setHT(100,2);
C3.setHT(100,3);
int num=0;
long long int item=0;

while(num<200){
    item=TCIDGen();
    if(C1.ins(item)){//insertion returns true if it was succesfull
        num++;
        C2.ins(item);
        C3.ins(item);
    }
}


//Answers to questions
cout<<"Q1)"<<endl;
cout<<"Loading Factor:"<<endl;
cout<<"Folding: "<<2<<endl;//method used to extract ratio Full Buckets
cout<<"Middle Squaring: "<<2<<endl;
cout<<"Truncation: "<<2<<endl<<endl;

cout<<"Q2)"<<endl;
cout<<"Number of Collisions out of 200 entries:"<<endl;
cout<<"Folding: "<<200-100*C1.Full()<<endl;
cout<<"Middle Squaring: "<<200-100*C2.Full()<<endl;
cout<<"Truncation: "<<200-100*C3.Full()<<endl<<endl;

cout<<"Reminder: Last 2 digits of the TC ID is generated according to official guidance,"<<endl;
cout<<"therefore results may differ from completely random TC ID Generation."<<endl<<endl;
cout<<"Q3)"<<endl;
cout<<"For this application the Folding has the best performance and Middle Squaring has the worst performance in terms of loading factor."<<endl<<endl;

return;
}
