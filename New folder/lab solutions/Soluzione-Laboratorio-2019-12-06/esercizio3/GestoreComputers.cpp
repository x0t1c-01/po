
#include "GestoreComputers.h"

#include <set>
using namespace std;

/*
Calcolare il massimo delle medie dei prezzi dei computers prodotti da ogni produttore.

Utilizzare la divisione intera.

Se non sono presenti computers, restituire -1.
            
*/
int GestoreComputers::metodo1()
{
    if(computers.empty())
		return -1;
	
	list<string> produttori;
	for(auto c : computers)
		produttori.push_back(c.getProduttore());

	int res = -1;
	for(auto p : produttori) {
		int avg = 0;
		int count = 0;
		for(auto c : computers) {
			if(c.getProduttore()==p) {
				avg += c.getPrezzo();
				count++;
			}
		}

		avg /= count;
		if(avg > res)
			res = avg;	
	}

	return res;
}

/*
Determinare la mediana dei computers ottenuta considerando la seguente relazione d'ordine:

Un computer C1 precede un computer C2 se il prezzo di C1 e' minore del prezzo di C2 e a parita' di prezzo, il tipo di C1 precede il tipo di C2 (ULTRABOOK precede NETBOOK precede NOTEBOOK).

Restituire il prezzo del computer che si trova in corrispondenza della mediana.

Nel caso in cui non ci siano computers presenti nel gestore, restituire -1.

NOTA BENE: calcolare mediana nel seguente modo: dopo aver ordinato gli oggetti si prende quello presente nel mezzo (utilizzare la divisione intera). 
            
*/
bool compare( const Computer& i, const Computer& j ) {
	if(i.getPrezzo() < j.getPrezzo())
		return true;
	if(i.getPrezzo() == j.getPrezzo())
		return i.getTipo() < j.getTipo();
	return false;
}

int GestoreComputers::metodo2()
{
    if(computers.empty())
		return -1;

	list<Computer> tmpList = computers;		
	tmpList.sort(compare);

	int middle = tmpList.size()/2;
	auto it = tmpList.begin();
	advance(it, middle);
	return it->getPrezzo();	
}

/*
Siano P1 e P2 produttori distinti tali per cui la somma dei prezzi di tutti i prodotti di P1 meno la somma dei prezzi di tutti i prodotti di P2 e' minima rispetto ad ogni altra coppia di produttori.
Determinare la posizione del primo produttore tra P1 e P2 in ordine di occorrenza nell'elenco.

Se non sono presenti computers o e' presente un solo produttore, restituire -1.

NOTA BENE: nel caso ci siano piu' coppie di produttori distinti che verificano la condizione, considerare il primo produttore in ordine di occorrenza nell'elenco che si trova in una di queste coppie.
            
*/
int GestoreComputers::metodo3() {
    if(computers.empty())
		return -1;
	
	list<string> produttori;	
	
	for(auto c : computers)
		if(find(produttori.begin(), produttori.end(), c.getProduttore()) == produttori.end())
			produttori.push_back(c.getProduttore());
	
	if(produttori.size() == 1)
		return -1;			    

	int min = INT_MAX;
	int max = INT_MIN;
	
	string produttoreMin;
	string produttoreMax;

    for(auto p : produttori) {
    	int somma = 0;
		for(auto c : computers)
			if(p == c.getProduttore())
				somma += c.getPrezzo();		

		if(somma < min) {
			min = somma;
			produttoreMin = p;
		}
		if(somma > max) {
			max = somma;
			produttoreMax = p;
		}
	}

	int count = 0;
	for(auto c : computers) {
		if(c.getProduttore() == produttoreMin || c.getProduttore() == produttoreMax)
			break;
		count++;
	}
	return count;
}

/*
Data la seguente definizione:
Un computer C1 e' connesso con un Computer C2 se:
- C1 e' connesso con C2, oppure
- C1 e' connesso con C3 e C3 e' connesso con C2.

Il metodo deve restituire il numero massimo di computer connessi tra loro.

Nel caso in cui non ci siano computers restituisce -1.
            
*/
bool esiste(const vector<string>& v, string c) {
	return find(v.begin(), v.end(), c) != v.end();
}

int GestoreComputers::metodo4() {
    if(computers.empty())
		return -1;

	list<string> nomi;
	for(auto c : computers)
		if(find(nomi.begin(), nomi.end(), c.getNomeComputer()) == nomi.end())
			nomi.push_back(c.getNomeComputer());
	
	int max = INT_MIN;
	for(auto n : nomi) {
		vector<string> visitati;
		vector<string> daVisitare;		
		daVisitare.push_back(n);
		int count = 0;	
		while(!daVisitare.empty()) {
			string computerCorrente = daVisitare.back();
			daVisitare.pop_back();
			visitati.push_back(computerCorrente);
			count++;

			for(auto c : computers) {
				if(c.getNomeComputer()==computerCorrente) {
					string c1 = c.getConnessoA();
					//Se c1 non è tra quelli già visitati e in quelli da visitare
					if(!esiste(visitati, c1) && !esiste(daVisitare, c1))
						daVisitare.push_back(c1);
				}
			}
		}
		if(count > max )
			max = count;
	}
	return max;
}
