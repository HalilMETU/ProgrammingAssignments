//Routes of the first month are added to the route map
void InitRouteMap(Routes& Gcity){
cout<<"----------------Month 1------------------:"<<endl<<"Routes:"<<endl;
int i=rand()%99+1;
Gcity.addGroute("Gulf of Archi","Logicheim",i,0);
i=rand()%99+1;
Gcity.addGroute("Probia","Gulf of Archi",i,0);
i=rand()%99+1;
Gcity.addGroute("Signale","Probia",i,0);
i=rand()%99+1;
Gcity.addGroute("Probia","Las Datas",i,0);
i=rand()%99+1;
Gcity.addGroute("Probia","Logicheim",i,0);
i=rand()%99+1;
Gcity.addGroute("Logicheim","Probia",i,0);

cout<<endl<<endl;
}


