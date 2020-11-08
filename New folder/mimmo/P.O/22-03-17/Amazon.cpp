
#include "Amazon.h"

/*
	Un venditore si considera affidabile se tutti gli articoli che vende 
	hanno una recensione diversa da "NESSUNA" e uguale o superiore a "QUATTRO_STELLE".
	Restituire il venditore affidabile con la somma dei prezzi piu' bassa 
	rispetto a tutti gli altri venditori affidabili.
	Se piu' venditori verificano questa proprieta' restituire il primo in ordine alfabetico.

	Se non sono presenti articoli, restituire "-1".
	Se non sono presenti venditori affidabili, restituire "-2".

	Ad esempio, se la lista di articoli contenesse:
		("Articolo1","venditoreA",10,TRE_STELLE,AMAZON_STANDARD)
		("Articolo2","venditoreB",20,QUATTRO_STELLE,AMAZON_STANDARD)
		("Articolo3","venditoreB",20,CINQUE_STELLE,AMAZON_STANDARD)
		("Articolo4","venditoreC",40,QUATTRO_STELLE,ALTRO)
		("Articolo5","venditoreD",5,CINQUE_STELLE,AMAZON_STANDARD)
		("Articolo6","venditoreD",15,NESSUNA,ALTRO)
	in cui per ogni articolo sono riportati (Nome,Venditore,Prezzo,Recensione,Spedizione),
	si otterrebbe:
		venditoreA	-> NON affidabile, somma prezzi 10		
		venditoreB	-> affidabile, somma prezzi 40
		venditoreC	-> affidabile, somma prezzi 40
		venditoreD	-> NON affidabile, somma prezzi 20
	pertanto, il metodo restituirebbe "venditoreB".
            
*/
string Amazon::metodo1()
{
    if(articoli.empty())
    	return "-1";
	vector<string> venditori;
	bool aff=true;
	int somma=0,index;
	int min=INT_MAX;
	vector<string> affidabili;
	for(list<Articolo>::iterator it=articoli.begin();it!=articoli.end();it++){
		if(find(venditori.begin(),venditori.end(),(it->getVenditore()))==venditori.end())
			venditori.push_back( (it->getVenditore()) );
	}
	for(int i=0;i<venditori.size();i++){
		for(list<Articolo>::iterator it=articoli.begin();it!=articoli.end();it++){
			if ( (it->getVenditore())==venditori[i] && ( (it->getRecensione())==0 ||  (it->getRecensione())<4) )
				aff=false;
		}
		if(aff==true)
			affidabili.push_back(venditori[i]);
		aff=true;
	}
	if(affidabili.empty())
		return "-2";
	cout<<affidabili.size()<<endl;
	for(int i=0;i<affidabili.size();i++){
		for(list<Articolo>::iterator it=articoli.begin();it!=articoli.end();it++){
			if( affidabili[i]==(it->getVenditore()) )
				somma+=(it->getPrezzo());
		}
		if(somma<min){
			min=somma;
			index=i;
		}
		//cout<<somma<<endl;
		somma=0;
	}
	return affidabili[index];
}

/*
	Sia R la recensione piu' ricorrente nella lista degli articoli.
	Restituire il prezzo medio degli articoli che hanno recensione R.
	Inoltre, si utilizzi una media intera. 

	Se piu' recensioni hanno la stessa ricorrenza considerare 
	la prima in ordine di apparizione nella lista.

	Se non sono presenti articoli, restituire -1.

	Ad esempio, se la lista di articoli contenesse:
		("Articolo1","venditoreA",10,TRE_STELLE,AMAZON_STANDARD)
		("Articolo2","venditoreB",20,QUATTRO_STELLE,AMAZON_STANDARD)
		("Articolo3","venditoreB",20,CINQUE_STELLE,AMAZON_STANDARD)
		("Articolo4","venditoreC",40,QUATTRO_STELLE,ALTRO)
		("Articolo5","venditoreD",5,CINQUE_STELLE,AMAZON_STANDARD)
		("Articolo6","venditoreD",15,NESSUNA,ALTRO)
	in cui per ogni articolo sono riportati (Nome,Venditore,Prezzo,Recensione,Spedizione),
	si otterrebbe:
		NESSUNA		-> 1 occorrenza, media prezzi 15
		UNA_STELLA	-> 0 occorrenze, media prezzi 0
		DUE_STELLE	-> 0 occorrenze, media prezzi 0
		TRE_STELLE	-> 1 occorrenza, media prezzi 10
		QUATTRO_STELLE	-> 2 occorrenze, media prezzi 30
		CINQUE_STELLE	-> 2 occorrenze, media prezzi 12
	pertanto, il metodo restituirebbe 30, ottenuto in corrispondenza di "QUATTRO_STELLE".
            
*/
int Amazon::metodo2()
{
	int cont=0,somma=0;
	int rec;
	int max=INT_MIN;
    if(articoli.empty())
    	return -1;
	for(list<Articolo>::iterator it=articoli.begin();it!=articoli.end();it++){
		for(list<Articolo>::iterator it1=articoli.begin();it1!=articoli.end();it1++){
			if( it!=it1 && (it->getRecensione())==(it1->getRecensione()))
				cont++;
		}
		if(cont>max){
			max=cont;
			rec=(it->getRecensione());
		}
		cont=0;
	}
	cont=0;
	for(list<Articolo>::iterator it=articoli.begin();it!=articoli.end();it++){
		if( (it->getRecensione())==rec ){
			cont++;
			somma+=(it->getPrezzo());
		}
	}
	return somma/cont;
	
}

/*
	Restituire il numero di articoli spediti solamente da Amazon, 
	ovvero gli articoli per cui come modalita' di spedizione e' presente AMAZON_PRIME e/o AMAZON_STANDARD.
	Se non sono presenti articoli nella lista, restituire -1.
	Se non sono presenti articoli che soddisfano questa proprieta', restituire -2.

	Ad esempio, se la lista di articoli contenesse:
		("Articolo1","venditoreA",10,TRE_STELLE,AMAZON_PRIME)
		("Articolo1","venditoreB",20,QUATTRO_STELLE,ALTRO)
		("Articolo2","venditoreB",20,CINQUE_STELLE,AMAZON_PRIME)
		("Articolo2","venditoreC",20,CINQUE_STELLE,AMAZON_STANDARD)
		("Articolo3","venditoreC",40,QUATTRO_STELLE,ALTRO)
		("Articolo4","venditoreC",40,QUATTRO_STELLE,AMAZON_PRIME)
	in cui per ogni articolo sono riportati (Nome,Venditore,Prezzo,Recensione,Spedizione),
	il metodo restituirebbe 2, poiche' "Articolo2" ed "Articolo4" sono gli unici articoli 
	che soddisfano questa proprieta'.
            
*/
int Amazon::metodo3()
{
	int cont=0;
    if(articoli.empty())
   		 return -1;
	list<string> nome;
	bool trovato=false;
	for(list<Articolo>::iterator it=articoli.begin();it!=articoli.end();it++){
		nome.push_back( (it->getNome()) );
	}
	nome.sort();
	nome.unique();
	//cout<<nome.size()<<endl;
	for(list<string>::iterator it=nome.begin();it!=nome.end();it++){
		for(list<Articolo>::iterator it1=articoli.begin();it1!=articoli.end();it1++){
			if( (it1->getNome())==(*it) && (it1->getSpedizione())==ALTRO )
				trovato=true; 
		}
		if(trovato==false)
			cont++;
		trovato=false;
	}
	return cont;
	
}

/*
	Dato un venditore V, siano:
		V1 il numero di prodotti con recensione "UNA_STELLA",
		V2 il numero di prodotti con recensione "DUE_STELLE",
		V3 il numero di prodotti con recensione "TRE_STELLE",
		V4 il numero di prodotti con recensione "QUATTRO_STELLE",
		V5 il numero di prodotti con recensione "CINQUE_STELLE".
	Il punteggio assegnato a V e' pari a:
		5 * V5 + 4 * V4 + 3 * V3 + 2 * V2 + 1 * V1

	Costruire una lista L in cui i venditori sono ordinati:
		- in ordine descrescente per punteggio,
		- a parita' di punteggio in ordine alfabetico (dalla A alla Z).

	Restituire il primo venditore in L.

	Se sono presenti meno di 2 venditori, restituire "-2".
	Se non sono presenti articoli nella lista, restituire "-1".

	Ad esempio, se la lista di articoli contenesse:
		("Articolo1","venditoreA",10,TRE_STELLE,AMAZON_STANDARD)
		("Articolo2","venditoreB",20,QUATTRO_STELLE,AMAZON_STANDARD)
		("Articolo3","venditoreB",20,CINQUE_STELLE,AMAZON_STANDARD)
		("Articolo4","venditoreC",40,QUATTRO_STELLE,ALTRO)
		("Articolo5","venditoreD",5,CINQUE_STELLE,AMAZON_STANDARD)
		("Articolo6","venditoreD",15,QUATTRO_STELLE,ALTRO)
	in cui per ogni articolo sono riportati (Nome,Venditore,Prezzo,Recensione,Spedizione),
	la lista L sarebbe cosi' costruita:
		venditoreB	-> punteggio 9
		venditoreD	-> punteggio 9
		venditoreC	-> punteggio 4
		venditoreA	-> punteggio 3		
	pertanto, il metodo restituirebbe "venditoreB".
 
            
*/
string Amazon::metodo4()
{
    if(articoli.empty())
    	return "-1";
	int v1=0,v2=0,v3=0,v4=0,v5=0;
	vector<string> venditori;
	for(list<Articolo>::iterator it=articoli.begin();it!=articoli.end();it++){
		if( find(venditori.begin(),venditori.end(),(it->getVenditore()))==venditori.end())
			venditori.push_back( (it->getVenditore()) );
	}
	if(venditori.size()<2)
		return "-2";
	vector<int> punteggi(venditori.size(),0);
	for(int i=0;i<venditori.size();i++){
		for(list<Articolo>::iterator it=articoli.begin();it!=articoli.end();it++){
			if( venditori[i]==(it->getVenditore()) && (it->getRecensione()==1) )
				v1++;	
			if( venditori[i]==(it->getVenditore()) && (it->getRecensione()==2) )
				v2++;
			if( venditori[i]==(it->getVenditore()) && (it->getRecensione()==3) )
				v3++;
			if( venditori[i]==(it->getVenditore()) && (it->getRecensione()==4) )
				v4++;
			if( venditori[i]==(it->getVenditore()) && (it->getRecensione()==5) )
				v5++;
		}
		punteggi[i]=(5*v5)+(4*v4)+(3*v3)+(2*v2)+(1*v1);
		//cout<<punteggi[i]<<endl;
		v1=0;
		v2=0;
		v3=0;
		v4=0;
		v5=0;
	}
	for(int i=0;i<punteggi.size();i++){
		for(int j=0;j<punteggi.size()-1;j++){
			if(punteggi[j]<punteggi[j+1]){
				swap(punteggi[j],punteggi[j+1]);
				swap(venditori[j],venditori[j+1]);
			}
			else if(punteggi[j]==punteggi[j+1]){
					if(venditori[j]>venditori[j+1])
						swap(venditori[j],venditori[j+1]);
			}
		}
	}
	return venditori.front();
}


