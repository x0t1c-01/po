#include "ProntoSoccorso.h"

unsigned int ProntoSoccorso::numeroPazientiInCoda(){
	return size();
}

void ProntoSoccorso::aggiungiPaziente(const Paziente& p){
	list<Paziente>::iterator it = begin();
	while ( it != end() && p <= (*it) )
		it++;
	insert(it,p);
	cout<<"Paziente aggiunto: ";p.stampa();
}

void ProntoSoccorso::serviProssimoPaziente(){
	if(!empty()){
		Paziente p=front();
		cout<<"Prossimo paziente: ";p.stampa();
		pop_front();
	}
}


