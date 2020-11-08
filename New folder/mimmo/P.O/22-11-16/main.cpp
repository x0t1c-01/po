#include"CalcolatriceAvanzata.h"
int main(){
	QuadruplaNumeri A(1,20,4,1231);
	QuadruplaNumeri B(3,4,71,9);
	QuadruplaNumeri C(3,4,7,1132);
	QuadruplaNumeri D(52,7,2,2123);
	QuadruplaNumeri E(51,5,2,3);
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
