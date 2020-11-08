#include<iostream>
#include"Mobilificio.h"
using namespace std;

int main()
{

    Mobile a("FSFS","MOMO",2000,TAVOLO,"SASA");
    Mobile b("DSD","SASA",3000,TAVOLO,"MOMO");
    Mobile c("EWE","MOMO",5000,TAVOLO,"TOTO");
    Mobile d("WER","SASA",2000,SEDIA,"SASA");
    Mobile e("TTT","MOMO",7000,COMODINO,"TOTO");
    Mobile f("VCVCV","TOTO",1000,COMODINO,"sosos");
    Mobile g("VwCVCV","TOTO",1000,COMODINO,"sosos");
    Mobilificio z;
    z.aggiungi(a);
    z.aggiungi(b);
    z.aggiungi(c);
    z.aggiungi(d);
    z.aggiungi(e);
    z.aggiungi(f);
    z.aggiungi(g);

    cout<<z.metodo1()<<endl;
    cout<<z.metodo2()<<endl;
    cout<<z.metodo3()<<endl;
    cout<<z.metodo4()<<endl;

    return 0;


}
