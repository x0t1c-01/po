#include"Giardino.h"

int main()
{
	Pianta A("Hedera", RAMPICANTE, 0, 5);
	Pianta B("Begonia", ARBUSTO, 10, 6);
	Pianta C("Glicine", RAMPICANTE, 2, 15);
	Pianta D("Aloe", ARBUSTO, 2, 10);
	Pianta E("Margherita", CESPUGLIO, 3, 3);
	Giardino z;
	z.aggiungi(A);
	z.aggiungi(B);
	z.aggiungi(C);
	z.aggiungi(D);
	z.aggiungi(E);

	cout << z.metodo3();
    return 0;
}
