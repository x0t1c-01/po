
#include "Giardino.h"

/*
	Sia C il tipo di pianta piu' frequente nel vettore delle piante
	(se piu' tipi hanno questa proprieta', prendere il primo di questi che compare nel vettore).
	Restituire la somma dei prezzi di tutte le piante con tipo C.

	Se non sono presenti piante, restituire -1.

	Ad esempio, se il vettore di piante contenesse:
		("Hedera",RAMPICANTE,0,5)
		("Begonia",ARBUSTO,10,6)
		("Glicine",RAMPICANTE,2,15)
		("Aloe",ARBUSTO,2,10)
		("Margherita",CESPUGLIO,3,3)
	in cui per ogni pianta sono riportati (Genere,Tipo,TemperaturaMinima,Prezzo),
	i tipi ARBUSTO e RAMPICANTE hanno la stessa frequenza: per entrambi sono presenti 2 piante;
	tuttavia nel vettore RAMPICANTE appare prima di ARBUSTO pertanto, il metodo restituirebbe 20.

*/
int Giardino::metodo1()
{
    if(piante.empty())
    return -1;
    int cont=0;
    Tipo tipomax;
    int max=INT_MIN;
    for(int i=0;i<piante.size();i++){
      cont=0;
        for(int j=0;j<piante.size();j++){
          if(piante[i].getTipo()==piante[j].getTipo())
            cont++;
        }
        if(cont>max){
			tipomax = piante[i].getTipo();
            max=cont;
          }
        }
        int somma=0;
    for(int i=0;i<piante.size();i++){
      if(piante[i].getTipo()==tipomax)
        somma+=piante[i].getPrezzo();
    }
    return somma;
}


/*
	Costruire una lista L in cui le piante sono ordinate:
		- in ordine in ordine alfabetico per genere (dalla A alla Z),
		- a parita' di genere in ordine crescente di prezzo (dal piu' piccolo al piu' grande).

	Restituire il prezzo della pianta che si trova nella posizione centrale di L (dimensione/2).

	Se non sono presenti piante, restituire -1.

	NOTA BENE: indipendentemente dal fatto che la dimensione di L e' pari o dispari,
	per determinare la pianta centrale utilizzare la divisione intera:
	prendendo l'elemento in posizione dimensione/2.

	Ad esempio, se il vettore di piante contenesse:
		("Hedera",RAMPICANTE,0,5)
		("Begonia",ARBUSTO,10,6)
		("Margherita",CESPUGLIO,3,3)
		("Aloe",ARBUSTO,2,10)
		("Aloe",ARBUSTO,5,15)
	in cui per ogni pianta sono riportati (Genere,Tipo,TemperaturaMinima,Prezzo),
	la lista L conterrebbe le piante nel seguente ordine:
		("Aloe",ARBUSTO,2,10)
		("Aloe",ARBUSTO,5,15)
		("Begonia",ARBUSTO,10,6)
		("Hedera",RAMPICANTE,0,5)
		("Margherita",CESPUGLIO,3,3)
	pertanto, dimensione/2 = 5/2 = 2, e dunque il metodo restituirebbe 6.

*/
bool ordina(Pianta p1, Pianta p2) {
	if (p1.getGenere() < p2.getGenere())
		return true;
	if (p2.getGenere() < p1.getGenere())
		return false;

	return p1.getPrezzo() < p2.getPrezzo();

}

int Giardino::metodo2()
{  return -1;



}

/*
	Sia X la lista di tutti e soli i generi (senza duplicati e nell'ordine in cui sono stati inseriti nel vettore)
	per i quali sono presenti nel giardino almeno 3 piante.

	Restituire l'ultimo genere presente in X.

	Se non sono presenti generi che soddisfano questa proprieta', restituire "0".
	Se non sono presenti piante, restituire "-1".

	Ad esempio, se il vettore di piante contenesse:
		("Hedera",RAMPICANTE,0,5)
		("Begonia",ARBUSTO,10,6)
		("Margherita",CESPUGLIO,3,3)
		("Margherita",CESPUGLIO,2,4)
		("Margherita",CESPUGLIO,1,5)
		("Aloe",ARBUSTO,5,8)
		("Aloe",ARBUSTO,3,10)
		("Aloe",ARBUSTO,1,15)
	in cui per ogni pianta sono riportati (Genere,Tipo,TemperaturaMinima,Prezzo),
	la lista X sarebbe cosi' formata:
		"Margherita"
		"Aloe"
	pertanto, il metodo restituirebbe "Aloe".

*/
string Giardino::metodo3()
{
    if(piante.empty())
		return "-1";
	vector <string> genere;
	for (int i = 0; i < piante.size(); i++) {
		if (almeno3(piante[i].getGenere()))
			if (find(genere.begin(), genere.end(), piante[i].getGenere()) == genere.end())
				genere.push_back(piante[i].getGenere());
	}
	if(genere.empty())
		return "0";
	return genere[genere.size()-1];

}

bool Giardino::almeno3(string x) {
	int cont = 0;
	for (int i = 0; i < piante.size(); i++) {
		if (piante[i].getGenere() == x)
			cont++;
	}
	if (cont >= 3)
		return true;
	return false;
}
/*
	Sia X la media delle temperature mimine tollerate calcolata su tutte le piante.
	Per calcolare X, si utilizzi una media intera.
	Sia L la lista di piante ordinate in ordine alfabetico per genere
	che hanno una temperatura minima tollerata minore di X.
	Restituire la stringa formata dalla concatenazione del genere della prima e dell'ultima pianta in L.

	Se non sono presenti piante che soddisfano questa proprieta', restituire "0".
	Se non sono presenti piante, restituire "-1".
	NB: nel caso in cui in L e' presente una sola pianta, la prima e l'ultima pianta coincidono.

	Ad esempio, se il vettore di piante contenesse:
		("Hedera",RAMPICANTE,0,5)
		("Begonia",ARBUSTO,10,6)
		("Glicine",RAMPICANTE,2,15)
		("Aloe",ARBUSTO,2,10)
		("Margherita",CESPUGLIO,3,3)
	la temperatura minima media e' pari a 3.4, come intero: 3.
	Dunque, L conterrebbe:
		("Aloe",ARBUSTO,2,10)
		("Glicine",RAMPICANTE,2,15)
		("Hedera",RAMPICANTE,0,5)
	pertanto, il metodo restituirebbe la stringa "AloeHedera".

*/
string Giardino::metodo4()
{
    /* IMPLEMENTARE QUESTO METODO */
    return "-1";
}
