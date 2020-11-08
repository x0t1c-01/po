#include"MatriceOrdinaria.h"
int main(){
	Punto A(0,0,3);
	Punto B(0,0,4);
	Punto C(1,0,4);
	Punto D(1,0,4);
	Punto E(2,2,1);
	Punto F(6,6,10);
	Punto G(2,1,7);
	MatriceOrdinaria Z;
	Z.aggiungi(A);
	Z.aggiungi(B);
	Z.aggiungi(C);
	Z.aggiungi(D);
	Z.aggiungi(E);
	Z.aggiungi(F);
	Z.aggiungi(G);
	cout<<Z.metodo2()<<endl;
	return 0;
}
