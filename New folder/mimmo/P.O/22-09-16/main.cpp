#include"Olimpiade.h"
int main(){
	Atleta A("LUCA","ITALIA",18,1,1,0);
	Atleta B("PINO","ITALIA",18,1,0,0);
	Atleta C("GIULIA","FINLANDIA",18,0,1,1);
	Atleta D("JACK","AMERICA",18,0,1,1);
	Atleta E("PIPPO","AMERICA",30,0,0,0);
	Olimpiade Z;
	Z.aggiungi(A);
	Z.aggiungi(B);
	Z.aggiungi(C);
	Z.aggiungi(D);
	Z.aggiungi(E);
	cout<<Z.metodo4()<<endl;
	return 0;
}
