#include "ProntoSoccorso.h"

int main(){
	Paziente p1("Mario",BIANCO);
	Paziente p2("Luca",BIANCO);
	Paziente p3("Laura",ROSSO);
	Paziente p4("Maria",GIALLO);
	Paziente p5("Renata",VERDE);
	Paziente p6("Raffaele",GIALLO);
	ProntoSoccorso l;
	l.aggiungiPaziente(p1);
	l.aggiungiPaziente(p2);
	l.aggiungiPaziente(p3);
	l.aggiungiPaziente(p4);
	l.aggiungiPaziente(p5);
	l.aggiungiPaziente(p6);
	
	cout<<"------------------"<<endl;
	
	while(l.numeroPazientiInCoda()>0)
	{
		l.serviProssimoPaziente();
	}
	
	return 0;
}