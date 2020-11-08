
#include "CalcolatriceAvanzata.h"
	int mcd(int a,int b){
		int r;
		while(b!=0){
				r=a%b;
				a=b;
				b=r;
		}
	return a;
	}
			

/*
	Restituire il numero con piu` occorrenze tra i num1 di tutte le quadruple presenti nella lista.
	Nel caso in cui piu` numeri hanno lo stesso numero di occorrenze restituire il piu` piccolo.

	Se la lista e` vuota restituire -1.

	Ad esempio, se la lista contiene:
	(1,2,4,3) (3,4,7,9) (3,4,7,1) (5,6,2,1) (5,5,2,3)
	Il numero 1 e` il num1 delle quadruple (1,2,4,3) per cui 1 volta.
	Il numero 3 e` il num1 delle quadruple (3,4,7,9) (3,4,7,1) per cui 2 volte.
	Il numero 5 e` il num1 delle quadruple (5,6,2,1) (5,5,2,3) per cui 2 volte.
	Poiche 3 < 5, il metodo deve restituire 3.
		    
*/
int CalcolatriceAvanzata::metodo1()
{
    if(numeri.empty())
    	return -1;
	int occ[numeri.size()];
	vector<int> num;
	int index=0;
	int max=-100;
	bool entrato=false;
	int cont=0;
	for(list<QuadruplaNumeri>::iterator it=numeri.begin();it!=numeri.end();it++)
		num.push_back( (it->getNum1()) );
	for(list<QuadruplaNumeri>::iterator it=numeri.begin();it!=numeri.end();it++){
		for(list<QuadruplaNumeri>::iterator it1=numeri.begin();it1!=numeri.end();it1++){
			if( (it->getNum1())==(it1->getNum1()) ){
				entrato=true;
				occ[cont]++;
			}
		}
		if(entrato==false)
			occ[cont]=0;
		cont++;
		entrato=false;
	}
	for(int i=0;i<numeri.size();i++){
		if(occ[i]>max){
			max=occ[i];
			index=i;
		}
		else if(occ[i]==max){
				if(num[i]<num[index]){
					index=i;
				}
		}
	}
	return num[index];
}

/*
	Due numeri A e B sono coprimi tra loro se non hanno nessun divisore comune eccetto 1 e -1.
	Una quadrupla di numeri C=(num1,num2,num3,num4) e` staordinaria se:
		- num1 e num2 sono coprimi,
		- num3 e num4 sono coprimi,
		- num4 e` dispari.
	Restituire il num4 dell'ultima quadrupla straordinaria presente nella lista.

	Se la lista e` vuota restituire -1.
	Se non sono presenti quadruple straordinarie, restituire -2.
	
	Ad esempio, se la lista contiene:
	(1,2,4,3) (3,4,7,9) (3,4,7,1) (5,6,2,1) (5,5,2,3)
	Sono quadruple straordinarie: (1,2,4,3) (3,4,7,9) (3,4,7,1) (5,6,2,1).
	Il metodo deve restituire 1, relativo alla quadrupla (5,6,2,1).
		        
*/
int CalcolatriceAvanzata::metodo2()
{
    if(numeri.empty())
    	return -1;
	vector<QuadruplaNumeri> straordinaria;
	for(list<QuadruplaNumeri>::iterator it=numeri.begin();it!=numeri.end();it++){
		if( mcd( (it->getNum1()),(it->getNum2()) )==1  && mcd((it->getNum3()),(it->getNum4()))==1 && ((it->getNum4())%2!=0) ){
			straordinaria.push_back( (*it) );
		}
	}
	if(straordinaria.size()==0)
		return -2;
	else
		return straordinaria[straordinaria.size()-1].getNum4();
}

/*
	Sia A il piu` grande numero di 4 cifre COSTRUIBILE utilizzando 
	i num1, num2 e num3 delle quadruple nella lista. 
	In particolare, a questo scopo considerare solo i num1, num2 e num3 
	composti da una sola cifra, ovvero >= 1 e <= 9.
	
	Sia B il piu` piccolo numero di 4 cifre presente tra 
	i num4 delle quadruple nella lista.	
	Restituire A-B.

	Se la lista e` vuota restituire -1.
	Se non esistono num4 di 4 cifre oppure 
	se non e` possibile costruire nessun numero di 4 cifre restituire -2.
	
	Ad esempio, se la lista contiene:
	(1,20,4,1231) (3,4,71,9) (3,4,7,1132) (52,7,2,2123) (51,5,2,3)
	Il numero A corrisponde a 7754.
	Il numero B corrisponde a 1132.
	Il metodo deve restituire 7754-1132 = 6622.
		    
*/

	int comp(int x,int y){return x>y;}
int CalcolatriceAvanzata::metodo3()
{
    if(numeri.empty())
    	return -1;
	vector<int> cifre;
	int cont=0;
	int A=0;
	int B=INT_MAX;
	for(list<QuadruplaNumeri>::iterator it=numeri.begin();it!=numeri.end();it++){
		if( (it->getNum1())>=1 && (it->getNum1())<=9 )
			cifre.push_back( (it->getNum1()) );
		if( (it->getNum2())>=1 && (it->getNum2())<=9 )
			cifre.push_back( (it->getNum2()) );
		if( (it->getNum3())>=1 && (it->getNum3())<=9 )
			cifre.push_back( (it->getNum3()) );
	}
	if(cifre.size()<4)
		return -2;
	sort(cifre.begin(),cifre.end(),comp);
	A=(A+cifre[0])*10;
	A=(A+cifre[1])*10;
	A=(A+cifre[2])*10;
	A=(A+cifre[3]);
	
	for(list<QuadruplaNumeri>::iterator it=numeri.begin();it!=numeri.end();it++){
		int n=(it->getNum4());
		while(n!=0){
				n=n/10;
				cont++;
		}
		if(cont==4 && (it->getNum4())<B)
			B=(it->getNum4());
		cont=0;
	}
	if(B==INT_MAX)
		return -2;
	cout<<A<<endl;
	cout<<B<<endl;
	return A-B;

	
	
	
}

/*
	Data una quadrupla (num1,num2,num3,num4), la sua somma e` calcolata come:
	 num1 + num2 + num3 + num4.
	Una quadrupla e` unica se:
		- il risultato della somma, S, e` un numero dispari, ed inoltre
		- non esiste alcuna quadrupla nella lista che abbia S come num3.
	Restituire il numero di quadruple uniche distinte nella lista.

	Se la lista e` vuota restituire -1.
	Se non sono presenti quadruple uniche, restituire 0.
	
	Ad esempio, se la lista contiene:
	(1,2,4,3) (3,4,7,9) (3,4,7,1) (3,4,7,9)
	Sono quadruple uniche: (3,4,7,9) (3,4,7,1).
	Il metodo deve restituire 2.
		        
*/
int CalcolatriceAvanzata::metodo4()
{
    if(numeri.empty())
    	return -1;
	vector<QuadruplaNumeri> uniche;
	bool trovato=false;
	int S=0;
	for(list<QuadruplaNumeri>::iterator it=numeri.begin();it!=numeri.end();it++){
		S=(it->getNum1())+(it->getNum2())+(it->getNum3())+(it->getNum4());
		if(S%2!=0){
			for(list<QuadruplaNumeri>::iterator it1=numeri.begin();it1!=numeri.end();it1++){
				if(S==(it1->getNum3()))
					trovato=true;
			}
			if(trovato==false && find(uniche.begin(),uniche.end(),(*it))==uniche.end())
				uniche.push_back((*it));
			trovato=false;
		}
	}
	return uniche.size();
}
			
						



