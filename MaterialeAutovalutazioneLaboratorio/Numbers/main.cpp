#include"CalcolatriceAvanzata.h"
int main(){
	TriplaNumeri A(3,1,1234);
	TriplaNumeri B(1,1,9);
	TriplaNumeri C(2,7,1132);
	TriplaNumeri D(52,2,2123);
	TriplaNumeri E(51,2,3);
	CalcolatriceAvanzata Z;
	Z.aggiungi(A);
	Z.aggiungi(B);
	Z.aggiungi(C);
	Z.aggiungi(D);
	Z.aggiungi(E);
	cout<<Z.metodo1()<<endl;
	cout<<Z.metodo2()<<endl;
			cout<<Z.metodo3()<<endl;
				cout<<Z.metodo4()<<endl;
	return 0;
}
