#include"Supermercato.h"
int main(){
	Prodotto A("Prod2",PESCHERIA,"riv1",20);
	Prodotto B("Prod2",ALTRO,"riv1",10);
	Prodotto C("Prod1",ALTRO,"riv3",20);
	Prodotto D("Prod1",ALTRO,"riv4",15);
	Supermercato S;
	S.aggiungi(A);
	S.aggiungi(B);
	S.aggiungi(C);
	S.aggiungi(D);
	//S.aggiungi(E);
	//S.aggiungi(F);
	cout<<S.metodo4()<<endl;
	return 0;
}
