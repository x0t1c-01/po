#include<iostream>
#include"Gioielleria.h"
using namespace std;

int main(){
	Gioiello a("O1", 150, OROLOGIO, ORO_BIANCO);
	Gioiello b("A1", 800, ANELLO, ORO_BIANCO);
	Gioiello d("OR1", 500, ORECCHINI, ORO_ROSA);
	Gioiello c("O2", 50, OROLOGIO, ACCIAIO);
	Gioiello e("A3", 500, ANELLO, ARGENTO);
    Gioiello f("A2", 600, ANELLO, ORO_GIALLO);
	Gioiello g("C1", 300, COLLANA, ORO_ROSA);
    Gioielleria L;
    L.aggiungi(a);
    L.aggiungi(g);
    L.aggiungi(b);
    L.aggiungi(c);
    L.aggiungi(d);
    L.aggiungi(e);
    L.aggiungi(f);


    cout<<L.metodo1();
    return 0;

}
