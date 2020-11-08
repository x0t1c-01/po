
#include "Museo.h"
#include <cmath>
/*
Restituire il numero di quadri dove la coordinata x < 10 e la coordinata y < 11.

Se non sono presenti opere restituire -1.
Se non sono presenti quadri restituire -2.
            
*/
int Museo::metodo1()
{
	bool quadro=false;
	if(opere.empty())
		return -1;
	int cont=0;
	for(list<Opera>::iterator it=opere.begin();it!=opere.end();it++){
		if( (it->getTipo())==0 && (it->getX())<10 && (it->getY())<11 )
			cont++;
		if( (it->getTipo())==0 )
			quadro=true;
	}
	if(quadro==false)
		return -2;
	else
		return cont;
		
 
}

/*
Calcolare la distanza massima tra due opere d'arte distinte.
Date due opere d'arte O1 e O2, la distanza e` calcolata come la radice quadrata di ((x2-x1)^2 + (y2-y1)^2); dove x1,y1 sono le coordinate di O1 e x2,y2 sono le coordinate di O2.
Utilizzare un intero per la distanza.

Se non sono presenti opere restituire -1.
Se e` presente solo un'opera d'arte restituire 0.
            
*/
int Museo::metodo2()
{
 	if( opere.empty())
		return -1;
	if(opere.size()==1)
		return 0;
	int max=INT_MIN;
	int x,y,z;
	for(list<Opera>::iterator it=opere.begin();it!=opere.end();it++){
		for(list<Opera>::iterator it1=opere.begin();it1!=opere.end();it1++){
			if(it!=it1){
				x= (it1->getX())-(it->getX());
				x=x*x;
				y= (it1->getY())-(it->getY());
				y=y*y;
				z=x+y;
				if(z>max)
					max=z;
			}
		}
	}
	return max;
	
	
}

/*
Restituire il numero di artisti che hanno realizzato almeno un quadro ma non hanno realizzato edifici.

Se non sono presenti opere restituire -1;
            
*/
int Museo::metodo3()
{
      if(opere.empty())
		return -1;
	int cont=0;
	int ris=0;
	bool edificio=false;
	vector<string> artisti;
	for(list<Opera>::iterator it=opere.begin();it!=opere.end();it++){
		if( find(artisti.begin(),artisti.end(),(it->getArtista()))==artisti.end() )
			artisti.push_back( (it->getArtista()) );
	}
	for(int i=0;i<artisti.size();i++){
		for(list<Opera>::iterator it=opere.begin();it!=opere.end();it++){
			if( (it->getArtista())==artisti[i] && (it->getTipo())==0 )
				cont++;
			if( (it->getArtista())==artisti[i] && (it->getTipo())==2 )
				edificio=true;
		}
		if(edificio==false && cont>=1)
  			ris++;
		edificio=false;
		cont=0;
	}
	return ris;
}

/*
Sia TMP una lista temporanea di opere d'arte contenenti tutte le opere d'arte del museo.
Ordinare TMP in accordo al seguente schema:
1) prima tutti i quadri in ordine alfabetico sul titolo.
2) poi tutte le statue in ordine alfabetico sul titolo.
3) poi tutti gli edifici in ordine alfabetico sul titolo.

Restituire il titolo dell'opera che si trova in ultima posizione di tmp.
Se non sono presenti opere restituire la stringa "-1";
            
*/
string Museo::metodo4()
{
   if(opere.empty())
		return "-1";
	vector<Opera> tmp;
	vector<string> quadri;
	vector<string> statue;
	vector<string> edifici;
	for(list<Opera>::iterator it=opere.begin();it!=opere.end();it++){
		if( (it->getTipo())==0 )
			quadri.push_back( (it->getTitolo()) );
		if( (it->getTipo())==1 )
			statue.push_back( (it->getTitolo()) );
		if( (it->getTipo())==2 )
			edifici.push_back( (it->getTitolo()) );
	}
	sort(quadri.begin(),quadri.end());
	sort(statue.begin(),statue.end());
	sort(edifici.begin(),edifici.end());
	for(int i=0;i<quadri.size();i++){
		for(list<Opera>::iterator it=opere.begin();it!=opere.end();it++){
			if( (it->getTitolo())==quadri[i] )
				tmp.push_back( (*it) );
		}
	}
	for(int i=0;i<statue.size();i++){
		for(list<Opera>::iterator it=opere.begin();it!=opere.end();it++){
			if( (it->getTitolo())==statue[i] )
				tmp.push_back( (*it) );
		}
	}
	for(int i=0;i<edifici.size();i++){
		for(list<Opera>::iterator it=opere.begin();it!=opere.end();it++){
			if( (it->getTitolo())==edifici[i] )
				tmp.push_back( (*it) );
		}
	}
	cout<<tmp.size()<<endl;
	return tmp.back().getTitolo();
}


