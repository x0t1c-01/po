
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
    if(atleti.empty())
    	return "-1";
	int min=INT_MAX,index;
	vector<string> nazioni;
	for(list<Atleta>::iterator it=atleti.begin();it!=atleti.end();it++){
		if( find(nazioni.begin(),nazioni.end(),(it->getNazione()))==nazioni.end() )
			nazioni.push_back( (it->getNazione()) );
	}
	vector<int> spese(nazioni.size(),0);
	for(int i=0;i<nazioni.size();i++){
		for(list<Atleta>::iterator it=atleti.begin();it!=atleti.end();it++){
			if( (it->getNazione())==nazioni[i] ){
				spese[i]+=(it->getNumeroOri())*20000;
				spese[i]+=(it->getNumeroArgenti())*15000;
				spese[i]+=(it->getNumeroBronzi())*10000;
			}
		}
	}
	for(int i=0;i<spese.size();i++){
		if(spese[i]<min){
			min=spese[i];
			index=i;
		}
		else if(spese[i]==min){
				index=i;
		}
	}
	return nazioni[index];


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
	int cont=0,x;
	int a=0,b=0,c=0;
    if(atleti.empty())
    	return -1;
	vector<string> nazioni;
	for(list<Atleta>::iterator it=atleti.begin();it!=atleti.end();it++){
		if(cont==2){
			x=(it->getNumeroOri());
		}
		if( find(nazioni.begin(),nazioni.end(),(it->getNazione()))==nazioni.end() )
			nazioni.push_back( (it->getNazione()) );
		cont++;
	}
	if(cont<3)
		return -1;
	cont=0;
	for(int i=0;i<nazioni.size();i++){
		for(list<Atleta>::iterator it=atleti.begin();it!=atleti.end();it++){
			if( (it->getNazione())==nazioni[i] ){
				a+=(it->getNumeroOri());
				b+=(it->getNumeroArgenti());
				c+=(it->getNumeroBronzi());
			}
		}
		if( a>b && b>c && a>x )
			cont++;
		a=0;
		b=0;
		c=0;
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
	int a=0,b=0,c=0,x;
    if(atleti.empty())
   		 return "-1";
	vector<string> nazioni;
	for(list<Atleta>::iterator it=atleti.begin();it!=atleti.end();it++){
		if( find(nazioni.begin(),nazioni.end(),(it->getNazione()))==nazioni.end() )
			nazioni.push_back( (it->getNazione()) );
	}
	vector<int> punteggi(nazioni.size(),0);
	for(int i=0;i<nazioni.size();i++){
		for(list<Atleta>::iterator it=atleti.begin();it!=atleti.end();it++){
			if( (it->getNazione())==nazioni[i] ){
				a+=(it->getNumeroOri());
				b+=(it->getNumeroArgenti());
				c+=(it->getNumeroBronzi());
			}
		}
		punteggi[i]=(a*3)+(b*2)+c;
		a=0;
		b=0;
		c=0;
	}
	for(int i=0;i<nazioni.size();i++){
		for(int j=0;j<nazioni.size()-1;j++){
			if(punteggi[j]<punteggi[j+1]){
				swap(punteggi[j],punteggi[j+1]);
				swap(nazioni[j],nazioni[j+1]);
			}
			else if(punteggi[j]==punteggi[j+1]){
					if(nazioni[j]>nazioni[j+1])
						swap(nazioni[j],nazioni[j+1]);
			}
		}
	}
	/*for(int i=0;i<nazioni.size();i++)
		cout<<nazioni[i]<<endl;*/
	return nazioni[nazioni.size()-1];



}

/*
Sia N la nazione con il maggior numero di atleti (In caso di piu` nazioni si consideri la prima in ordine alfabetico).
Restituire il nome dell'atleta meno giovane appartenente alla nazione N (In caso di piu` atleti si consideri il primo in ordine alfabetico).

Se non sono presenti atleti, restituire "-1".

*/
string Olimpiade::metodo4()
{
	int max=INT_MIN,cont=0,index;
	string a;
    if(atleti.empty())
    	return "-1";
	vector<string> nazioni;
	for(list<Atleta>::iterator it=atleti.begin();it!=atleti.end();it++){
		if( find(nazioni.begin(),nazioni.end(),(it->getNazione()))==nazioni.end() )
			nazioni.push_back( (it->getNazione()) );
	}
	sort(nazioni.begin(),nazioni.end());
	for(int i=0;i<nazioni.size();i++){
		for(list<Atleta>::iterator it=atleti.begin();it!=atleti.end();it++){
			if( (it->getNazione())==nazioni[i] ){
				cont++;
			}
		}
		if(cont>max){
			max=cont;
			index=i;
		}
		cont=0;
	}
	cont=0;
	max=INT_MIN;
	for(list<Atleta>::iterator it=atleti.begin();it!=atleti.end();it++){
			if( (it->getNazione())==nazioni[index] ){
				if( (it->getEta())>max ){
					max=(it->getEta());
					a=(it->getAtleta());
				}
			}
	}
	return a;





}
