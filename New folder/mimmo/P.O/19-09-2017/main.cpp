#include"Giardino.h"
int main() 
{
	Pianta A("Hedera",RAMPICANTE,0,5);
	Pianta B("Begonia",ARBUSTO,10,6);
	Pianta C("Glicine",RAMPICANTE,2,15);
	Pianta D("Aloe",ARBUSTO,2,10);
	Pianta E("Margherita",CESPUGLIO,3,3);
	Giardino Z;
	Z.aggiungi(A);
	Z.aggiungi(B);
	Z.aggiungi(C);
	Z.aggiungi(D);
	Z.aggiungi(E);
	cout<<Z.metodo4()<<endl;
    return 0;
}
