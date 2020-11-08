
#include "Cinema.h"

/*
Restituire il genere di film che ha incassato di piu' tra quelli presenti nella lista (escludendo i film per cui il genere e' NONDEFINITO). 
Se due generi diversi hanno incassato lo stesso importo massimo restituire il primo in ordine alfabetico (esempio, ANIMAZIONE precede COMICO)
Se non sono presenti film o se tutti i film hanno il genere NONDEFINITO, restituire NONDEFINITO.
            
*/
Genere Cinema::metodo1()
{
	int somma=0,cont=0,media,index;
	int max=INT_MIN;
    if(film.empty())
    	return NONDEFINITO;
	vector<Genere> generi(8);
	for(int i=0;i<generi.size();i++){
		for(list<Film>::iterator it=film.begin();it!=film.end();it++){
			if( (it->getGenere())==i){
				somma+=(it->getIncasso());
			}
		}
		//cout<<somma<<endl;
		if(somma>max){
			max=somma;
			index=i;
		}
		somma=0;
	}
	if(generi.size()==0 || index==0)
		return NONDEFINITO;
	else{
		for(list<Film>::iterator it=film.begin();it!=film.end();it++){
			if( (it->getGenere())==index)
				return (it->getGenere());
		}
	}
		
		
		
}

/*
Sia A l'anno piu' recente di un film nella lista.
Determinare il regista che ha diretto meno film nell'anno A.
Se due o piu' registi hanno diretto lo stesso numero minimo di film nell'anno A, restituire il primo in ordine alfabetico.
Se non sono presenti film, restituire "-1".
            
*/
string Cinema::metodo2()
{
    if(film.empty())
    	return "-1";
	int max=INT_MIN;
	string reg;
	int n=0;
	int min=INT_MAX;
	vector<string> registi;
	for(list<Film>::iterator it=film.begin();it!=film.end();it++){
		if( find(registi.begin(),registi.end(),(it->getRegista()))==registi.end() )
			registi.push_back( (it->getRegista()) );
		if( (it->getAnno())>max)
			max=(it->getAnno());
	}
	sort(registi.begin(),registi.end());
	for(int i=0;i<registi.size();i++){
		for(list<Film>::iterator it=film.begin();it!=film.end();it++){
			if( (it->getRegista())==registi[i] && (it->getAnno())==max )
				n++;
		}
		if(n<min){
			reg=registi[i];
			min=n;
		}
		n=0;
	}
	return reg;
	
		
}

/*
Un regista e' detto settoriale se almeno il 70% dei suoi film sono dello stesso genere (includendo il genere NONDEFINITO).
Restituire il numero di registi settoriali.
Se non sono presenti film, restituire -1.

Esempio:
Un regista che ha diretto due film di ANIMAZIONE e un film COMICO NON E' settoriale (67% dei film di ANIMAZIONE e 33% COMICO).
Un regista che ha diretto tre film di COMICO e un film COMMEDIA E' settoriale (75% dei film di COMICO e 25% COMMEDIA).

            
*/
int Cinema::metodo3()
{
    /* IMPLEMENTARE QUESTO METODO */
    return -1;
}

/*
Data una qualsiasi coppia di film F1, F2 la differenza di incasso tra i due film e' l'incasso di F1 - l'incasso di F2.
Restituire la differenza di incasso piu' alta tra i film presenti nella lista.
Se sono presenti meno di 2 film nella lista, restituire -1.
            
*/
int Cinema::metodo4()
{
	int s;
	int max=INT_MIN;
    if(film.empty())
    	return -1;
	if(film.size()<2)
		return -2;
	for(list<Film>::iterator it=film.begin();it!=film.end();it++){
		for(list<Film>::iterator it1=film.begin();it1!=film.end();it1++){
			s=(it->getIncasso())-(it1->getIncasso());
			//cout<<s<<endl;
			if(s>max)
				max=s;
		}
	}
	return max;
}


