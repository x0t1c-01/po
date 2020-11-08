#include"Sudoku.h"
int main() 
{
	Cella A(1,1,3);
	Cella B(1,1,4);
	Cella C(1,1,4);
	Cella D(2,2,3);
	Cella E(3,2,3);
	Cella F(2,5,3);
	Cella G(2,5,2);
	Cella H(3,1,3);
	Cella I(3,2,2);
	Cella J(3,2,2);
	Sudoku Z;
	Z.aggiungi(A);
	Z.aggiungi(B);
	Z.aggiungi(C);
	Z.aggiungi(D);
	Z.aggiungi(E);
	//Z.aggiungi(F);
	//Z.aggiungi(G);
	//Z.aggiungi(H);
	//Z.aggiungi(I);
	//Z.aggiungi(J);
	cout<<Z.metodo2()<<endl;
    return 0;
}
