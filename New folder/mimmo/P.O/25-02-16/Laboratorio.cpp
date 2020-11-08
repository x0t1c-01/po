
#include "Laboratorio.h"

/*
Sia E l'esperimento che ha il tempo medio (la media tra tempo1, tempo2 e tempo3) maggiore (nel caso di esperimenti con lo stesso tempo medio prendere il primo in ordine di apparizione nella lista).
Restituire la media del costo di tutti gli esperimenti condotti dallo scienziato che ha condotto E.
Se non sono presenti esperimenti, restituire -1.

Per la medie utilizzare la divisione intera.
            
*/
int Laboratorio::metodo1()
{
    if(esperimenti.empty())
    	return -1;
	int E=0,max=INT_MIN;
	int cont=0,somma=0;
	string a;
	for(list<Esperimento>::iterator it=esperimenti.begin();it!=esperimenti.end();it++){
		E=(it->getTempo1())+(it->getTempo2())+(it->getTempo3());
		E=E/3;
		if( E>max) {
			max=E;
			a=(it->getScienziato());
		}
	}
	cout<<a<<endl;
	for(list<Esperimento>::iterator it=esperimenti.begin();it!=esperimenti.end();it++){
		if( (it->getScienziato())==a ){
			cont++;
			somma+=(it->getCosto());
		}
	}
	cout<<somma<<endl;
	somma=somma/cont;
	return somma;
	
	
			
}

/*
Sia M(E) la media intera tra tempo1, tempo2 e tempo3 di un esperimento E.
Un esperimento E e' considerato straordinario se esiste almeno uno esperimento E1 tale che M(E1) > M(E).

Restituire il numero di esperimenti straordinari.
Se non sono presenti esperimenti, restituire -1.
            
*/
int Laboratorio::metodo2()
{
    if(esperimenti.empty())
    	return -1;
	int M,M1,cont=0;
	for(list<Esperimento>::iterator it=esperimenti.begin();it!=esperimenti.end();it++){
		M=(it->getTempo1())+(it->getTempo2())+(it->getTempo3());
		M=M/3;
		for(list<Esperimento>::iterator it1=esperimenti.begin();it1!=esperimenti.end();it1++){
			M1=(it1->getTempo1())+(it1->getTempo2())+(it1->getTempo3());
			M1=M1/3;
			if(M1>M){
				cont++;
				break;
			}
		}
	}
	return cont;
}

/*
Data una qualsiasi tripla di esperimenti (E1,E2,E3).
Il costo della tripla e' dato costo di E1 + costo di E2 - costo di E3.
Sia T la tripla con il costo piu' basso tra tutte le possibili triple della lista.
Restituire il costo di T.

Se non sono presenti esperimenti, restituire -1.

N.B. una tripla di esperimenti puo' contenere piu' volte lo stesso esperimento.
            
*/
int Laboratorio::metodo3()
{
    if(esperimenti.empty())
    	return -1;
	
}

/*
Sia E il primo esperimento della lista e sia S(E) la somma tra tempo1, tempo2 e tempo3 di E.

Un esperimento e' considerato veloce se la somma tra tempo1, tempo2 e tempo3 e' minore o uguale a S(E).
Uno scienziato e' considerato bravo se i suoi esperimenti sono tutti veloci e se la somma dei costi dei suoi esperimenti e' minore o uguale del costo di E.

Restituire il primo scienziato bravo in ordine di apparizione nella lista.

Se non sono presenti esperimenti, restituire la stringa "-1".
Se non sono presenti scienzati bravi restituire la stringa "-2".
            
*/
string Laboratorio::metodo4()
{
    if(esperimenti.empty())
    	return "-1";
	string a;
	bool veloce=true;
	int cont=0;
	int costo,S;
	int somma=0,somma1=0;
	vector<string> scienziati;
	for(list<Esperimento>::iterator it=esperimenti.begin();it!=esperimenti.end();it++){
		if(scienziati.size()==0){
			costo=(it->getCosto());
			S=(it->getTempo1())+(it->getTempo2())+(it->getTempo3());
		}
		if( find(scienziati.begin(),scienziati.end(),(it->getScienziato()))==scienziati.end() )
			scienziati.push_back( (it->getScienziato()) );
	}
	//cout<<costo<<S<<endl;
	for(int i=0;i<scienziati.size();i++){
		for(list<Esperimento>::iterator it=esperimenti.begin();it!=esperimenti.end();it++){
			if( (it->getScienziato())==scienziati[i] ){
				somma+=(it->getCosto());
				somma1=(it->getTempo1())+(it->getTempo2())+(it->getTempo3());
				if(somma1>S)
					veloce=false;
			}	
		}
		if( veloce==true && somma<=costo ){
			cont++;
			a=scienziati[i];
			break;
		}
		veloce=true;
		somma=0;
	}
	if(cont==0)
		return "-2";
	else
		return a;
		







		
			
	
}


