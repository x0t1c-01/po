#include"Laboratorio.h"
int main() 
{
	Esperimento A("Esperimento1","Luca",1,2,3,10);				//S=6,costo=10,
	Esperimento B("Esperimento2","Luca",1,1,1,15);
	Esperimento C("Esperimento3","Giorgio",0,2,1,55);
	Esperimento D("Esperimento4","Luca",2,2,1,15);
	Esperimento E("Esperimento5","Pippo",1,0,0,1);
	Laboratorio Z;
	Z.aggiungi(A);
	Z.aggiungi(B);
	Z.aggiungi(C);
	Z.aggiungi(D);
	Z.aggiungi(E);
	cout<<Z.metodo4()<<endl;
    return 0;
}
