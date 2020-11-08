#include"AnalizzatoreCerchi.h"
int main(){
		Cerchio A(1,1,3);
		Cerchio B(2,4,4);
		Cerchio C(4,6,3);
		Cerchio D(10,0,4);
		Cerchio E(0,5,1);
	AnalizzatoreCerchi Z;
	Z.aggiungi(A);
	Z.aggiungi(B);
	Z.aggiungi(C);
	Z.aggiungi(D);
	Z.aggiungi(E);
	cout<<Z.metodo4()<<endl;
	return 0;
}
