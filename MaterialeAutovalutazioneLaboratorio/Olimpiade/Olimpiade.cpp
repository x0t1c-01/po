
#include "Olimpiade.h"

/*
Restituire la nazione che ha speso meno. Ogni nazione paga i suoi atleti come segue:
	- 10.000 Euro per ogni medaglia di bronzo,
	- 15.000 Euro per ogni medaglia di argento,
	- 20.000 Euro per ogni medaglia di oro.

In caso siano presenti due o piu' nazioni con la stessa spesa minima restituire la seconda in ordine di apparizione nella lista di atleti.

Se non sono presenti atleti, restituire "-1".

*/
string Olimpiade::metodo1()
{
    /* IMPLEMENTARE QUESTO METODO */
	if(atleti.empty())
		return "-1";
	vector <string> nazioni;
	for(auto it=atleti.begin();it!=atleti.end();it++){
		if(find(nazioni.begin(),nazioni.end(),(it->getNazione()))==nazioni.end()){
			nazioni.push_back((it->getNazione()));
		}
	}
	int spesamin=INT_MAX;
	string s;
	for(int i=0;i<nazioni.size();i++){
		int costonazione=0;
		for(auto it=atleti.begin();it!=atleti.end();it++){
			if(nazioni[i]==(it->getNazione())){
				costonazione+=(it->getNumeroOri())*20000;
				costonazione+=(it->getNumeroArgenti())*15000;
				costonazione+=(it->getNumeroBronzi())*10000;
			}
		}
		if(costonazione<spesamin){
			spesamin=costonazione;
			s=nazioni[i];
		}
	}

    return s;
}

/*
Sia X il numero di ori vinti dal terzo atleta presente nella lista atleti.

Sia N_ori il numero di ori, N_argenti il numero di argenti, N_bronzi il numero di bronzi,
vinti dagli atleti di una nazione, tale nazione si definisce vittoriosa se:
	N_ori > N_argenti > N_bronzi
ed inoltre, N_ori > X.

Restituire il numero di nazioni vittoriose.

Se non sono presenti atleti oppure ne sono presenti meno di 3, restituire -1.


*/
int Olimpiade::metodo2()
{
    /* IMPLEMENTARE QUESTO METODO */

	if(atleti.empty()||atleti.size()==3)
		return -1;
	vector <string> nazioni;
	int x;
	int contatore=0;
	for(auto it=atleti.begin();it!=atleti.end();it++){
		if(contatore==2)
			x=(it->getNumeroOri());

		if(find(nazioni.begin(),nazioni.end(),(it->getNazione()))==nazioni.end()){
			nazioni.push_back((it->getNazione()));
		}
		contatore++;
	}
	int cont=0;
	for(int i=0;i<nazioni.size();i++){
		int contoro=0,contargento=0,contbronzo=0;
		for(auto it=atleti.begin();it!=atleti.end();it++){
			if(nazioni[i]==(it->getNazione())){
				contoro+=(it->getNumeroOri());
				contargento+=(it->getNumeroArgenti());
				contbronzo+=(it->getNumeroBronzi());
			}
		}
		if(contoro>contargento && contargento>contbronzo && contoro>x)
			cont++;
	}


    return cont;
}

/*
Creare una lista di nazioni ordinate in ordine descrescente in base al punteggio ottenuto, e a parita' di punteggio in ordine alfabetico.

Sia N_ori il numero di ori, N_argenti il numero di argenti, N_bronzi il numero di bronzi,
vinti dagli atleti di una nazione, il punteggio ottenuto da questa nazione e' calcolato come:
	N_ori * 3 + N_argenti * 2 + N_bronzi

Restituire la nazione in ultima posizione nella lista cosi' ottenuta.

Se non sono presenti atleti, restituire "-1".

ATTENZIONE: Non modificare la lista atleti.

*/
string Olimpiade::metodo3()
{
    /* IMPLEMENTARE QUESTO METODO */
	if(atleti.empty())
		return "-1";
	vector <string> nazioni;
	for(auto it=atleti.begin();it!=atleti.end();it++){
		if(find(nazioni.begin(),nazioni.end(),(it->getNazione()))==nazioni.end()){
			nazioni.push_back((it->getNazione()));
		}
	}

	vector<int> punteggio(nazioni.size(),0);
	for(int i=0;i<nazioni.size();i++){
		int contoro=0,contargento=0,contbronzo=0;
		for(auto it=atleti.begin();it!=atleti.end();it++){
			if(nazioni[i]==(it->getNazione())){
				contoro+=(it->getNumeroOri());
				contargento+=(it->getNumeroArgenti());
				contbronzo+=(it->getNumeroBronzi());
			}
		}
		punteggio[i]=(contoro*3)+(contargento*2)+contbronzo;
	}

	for(int i=0;i<punteggio.size();i++){
		for(int j=0;j<punteggio.size()-1;j++){
			if(punteggio[j]<punteggio[j+1]){
			swap(punteggio[j],punteggio[j+1]);
			swap(nazioni[j],nazioni[j+1]);
			}
			else if(punteggio[j]==punteggio[j+1]){
				if(nazioni[j]>nazioni[j+1])
					swap(nazioni[j],nazioni[j+1]);
			}
		}
	}

    return nazioni[nazioni.size()-1];
}

/*
Sia N la nazione con il maggior numero di atleti (In caso di piu` nazioni si consideri la prima in ordine alfabetico).
Restituire il nome dell'atleta meno giovane appartenente alla nazione N (In caso di piu` atleti si consideri il primo in ordine alfabetico).

Se non sono presenti atleti, restituire "-1".

*/
string Olimpiade::metodo4()
{
    /* IMPLEMENTARE QUESTO METODO */
	if(atleti.empty())
		return "-1";
	vector <string> nazioni;
	for(auto it=atleti.begin();it!=atleti.end();it++){
		if(find(nazioni.begin(),nazioni.end(),(it->getNazione()))==nazioni.end()){
			nazioni.push_back((it->getNazione()));
		}
	}
		vector<int> numat(nazioni.size(),0);
		for(int i=0;i<nazioni.size();i++){
			int contat=0;
			for(auto it=atleti.begin();it!=atleti.end();it++){
				if(nazioni[i]==it->getNazione())
					contat++;
			}
			numat[i]=contat;
		}

		for(int i=0;i<numat.size();i++){
			for(int j=0;j<numat.size()-1;j++){
				if(numat[j]<numat[j+1]){
					swap(numat[j],numat[j+1]);
					swap(nazioni[j],nazioni[j+1]);
				}
				else if(numat[j]==numat[j+1]){
					if(nazioni[j]>nazioni[j+1])
						swap(nazioni[j],nazioni[j+1]);
				}
			}
		}
		int eta=INT_MAX;
		string q;
		for(auto it=atleti.begin();it!=atleti.end();it++){
			if(nazioni[0]==(it->getNazione()))
			{
				if((it->getEta()<eta)){
					eta=(it->getEta());
					q=(it->getAtleta());
				}
			}
		}

    return q;
}
