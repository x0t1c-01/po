#include"Museo.h"
int main() 
{
	Opera A("MARE","LUCA",8,9,EDIFICIO);
	Opera B("LA NOTTE","LUCA",7,9,QUADRO);				
	Opera C("DAVID","PIPPO",50,10,QUADRO);
	Opera D("IL BACIO","GIULIA",10,5,QUADRO);
	Museo Z;
	Z.aggiungi(A);
	Z.aggiungi(B);
	Z.aggiungi(C);
	Z.aggiungi(D);
	cout<<Z.metodo2()<<endl;
    return 0;
}
