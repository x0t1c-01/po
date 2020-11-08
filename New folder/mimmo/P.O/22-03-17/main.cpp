#include"Amazon.h"
int main(){
	Articolo A("Articolo1","venditoreA",10,TRE_STELLE,AMAZON_STANDARD);
	Articolo B("Articolo2","venditoreB",20,QUATTRO_STELLE,AMAZON_STANDARD);
	Articolo C("Articolo3","venditoreB",20,CINQUE_STELLE,AMAZON_STANDARD);
	Articolo D("Articolo4","venditoreC",40,QUATTRO_STELLE,ALTRO);
	Articolo E("Articolo5","venditoreD",5,CINQUE_STELLE,AMAZON_STANDARD);
	Articolo F("Articolo6","venditoreD",15,NESSUNA,ALTRO);
	Amazon Z;
	Z.aggiungi(A);
	Z.aggiungi(B);
	Z.aggiungi(C);
	Z.aggiungi(D);
	Z.aggiungi(E);
	Z.aggiungi(F);
	cout<<Z.metodo1()<<endl;
	return 0;
}
