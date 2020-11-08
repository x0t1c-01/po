#include "Sudoku.h"

/*
Restituire il numero di righe in cui c'e' almeno un simbolo 
presente in colonne distinte.

Se non sono presenti celle restituire -1.
Se non sono presenti righe che soddisfano tale proprieta' restituire 0.

Ad esempio, se il Sudoku contenesse:
(1,2,3)
(1,3,3)
(1,4,4)
(1,5,4)
(2,2,3)
(2,5,3)
(2,5,2)
(3,1,3)
(3,2,2)
(3,2,2)
in cui ogni cella e' rappresentata come una tripla (R,C,S), 
dove R e' la riga, C la colonna, S il simbolo, otterremmo che:
 - per la riga 1, i simboli 3 e 4 si trovano ciascuno su due colonne diverse,
 - per la riga 2, il simbolo 3 il simbolo 3 si trova su due colonne diverse.
 - per la riga 3, ogni simbolo e' presente su una sola colonna.
Pertato soltanto le righe 1 e 2 soddisferebbero tale proprieta' ed il metodo restituirebbe 2.
            
*/
int Sudoku::metodo1()
{
    if(sudoku.empty()) return -1;

    list<int> righe;

    for(list<Cella>::iterator it = sudoku.begin(); it != sudoku.end(); it++)
    {
        int riga=it->getRiga();
        int simbolo=it->getSimbolo();
        int colonna=it->getColonna();
        for(list<Cella>::iterator it2 = sudoku.begin(); it2 != sudoku.end(); it2++)
            if(it2->getColonna()!=colonna && it2->getRiga()==riga && it2->getSimbolo()==simbolo)
                righe.push_back(riga);
    }

    righe.sort();
    righe.unique();

    return righe.size();
}

/*
Restituire il numero di coordinate riga e colonna a cui non e' associato alcun simbolo.

Se non sono presenti celle restituire -1.
Se non sono presenti coppie di coordinate riga e colonna 
che soddisfano tale proprieta' restituire 0.

Si ricorda che ogni cella e' composta da una riga, una colonna e un simbolo.
Indichiamo una cella come una tripla (R,C,S), dove R e' la riga, C la colonna, S il simbolo.
Ad esempio (1,2,3) rappresenta la cella che ha come riga 1, come colonna 2 e come simbolo 3.

Ad esempio, se il Sudoku contenesse:
(1,1,3)
(1,1,4)
(1,1,4)
(2,2,3)
(3,2,3)
in cui ogni cella e' rappresentata come una tripla (R,C,S), 
dove R e' la riga, C la colonna, S il simbolo, 
il metodo restituirebbe 78, in quanto tutte le possibili
coppie di coordinate ad eccezione di (1,1), (2,2) e (3,2) 
non avrebbero associato alcun simbolo.
            
*/
int Sudoku::metodo2()
{
    if(sudoku.empty()) return -1;

    int count=0;
    for(int i=1;i<=9;++i){
        for(int j=1;j<=9;++j){
            bool presente=false;
            for(list<Cella>::iterator it = sudoku.begin(); it != sudoku.end(); it++)
            {
                if(it->getRiga()==i && it->getColonna()==j)
                    presente=true;
            }
            if(!presente)
                count++;
        }
    }
    
    return count;
}

/*
Un Sudoku viene diviso in 9 blocchi di dimensione 3x3. Ogni blocco occupa una regione 
differente, e i blocchi si considerano numerati da 1 a 9.
Sia (R,C) una  coppia di coordinate riga e colonna, 
per individuare a quale blocco appartiene, e' sufficiente calcolare:
	((C-1)/3) + (((R-1)/3)*3) + 1
NB: si utilizzi la divisione intera (ad esempio 2/3=0).

Restituire il numero del blocco per cui la somma dei simboli distinti
presenti e' minima, ed in cui si trova almeno un simbolo.
Se piu' blocchi soddisfano tale proprieta', 
restituire l'ultimo blocco in ordine crescente.

Se non sono presenti celle restituire -1.

Ad esempio, se il Sudoku contenesse:
(1,1,3)
(1,1,4)
(1,1,4)
(2,2,3)
(3,2,3)
(9,9,1)
(9,8,1)
(4,4,2)
in cui ogni cella e' rappresentata come una tripla (R,C,S), 
dove R e' la riga, C la colonna, S il simbolo, otterremmo che:
 - le celle (1,1,3), (1,1,4), (1,1,4), (2,2,3), (3,2,3) apparterrebbero al blocco 1,
 	somma -> 3 + 4 = 7,
 - le celle (9,9,1), (9,8,1) apparterrebbero al blocco 9,
 	somma -> 1,
 - la cella (4,4,2) apparterrebbe al blocco 5,
 	somma -> 2.
Pertanto il metodo restituirebbe 9.
            
*/
int Sudoku::metodo3()
{
    if(sudoku.empty()) return -1;

    int min=INT_MAX;
    int bloccoMin=0;
    for(int i=1;i<=9;i++){
        list<int> simboli;
        for(list<Cella>::iterator it2 = sudoku.begin(); it2 != sudoku.end(); it2++){
            int blocco=((it2->getColonna()-1)/3) + (((it2->getRiga()-1)/3)*3) + 1;
            if(blocco==i)
                simboli.push_back(it2->getSimbolo());
        }
        simboli.sort();
        simboli.unique();
        int somma=0;
        for(list<int>::iterator it = simboli.begin(); it != simboli.end(); it++) 					
            somma+=*it;
        if(somma>0 && min>somma){
            min=somma;
            bloccoMin=i;
        }
        else if(somma>0 && min==somma && i>bloccoMin){
            bloccoMin=i;
        }
    }
    
    return bloccoMin;
}

/*
Immaginate il Sudoku come una matrice quadrata di 9 righe e 9 colonne.            
Sia S1 la somma ottenuta dai simboli presenti nelle celle che 
hanno le coordinate di riga e colonna sulla diagonale principale oppure 
al di sotto della diagonale principale.
Sia S2 la somma ottenuta dai simboli presenti nelle celle che 
hanno le coordinate di riga e colonna sulla diagonale secondaria.

NB: nel caso in cui alla stessa coppia di coordinate di riga e colonna 
siano associati piu' simboli considerare il primo in ordine di apparizione nella lista.

Restituire S1-S2.

Se non sono presenti celle restituire -1.

Ad esempio, se il Sudoku contenesse:
(1,1,1)
(2,1,2)
(2,2,4)
(2,2,3)
(3,3,3)
(4,4,4)
(4,4,4)
(1,9,7)
(2,8,6)
(3,7,5)
(4,6,4)
(1,8,9)
(1,8,9)
in cui ogni cella e' rappresentata come una tripla (R,C,S), 
dove R e' la riga, C la colonna, S il simbolo, otterremmo che:
 - le seguenti celle contribuirebbero alla somma S1: 
	(1,1,1), (2,1,2), (2,2,4), (3,3,3), (4,4,4),
	dunque S1 corrisponderebbe a 1+2+4+3+4=17.
 - le seguenti celle contribuirebbero alla somma S2: 
 	(1,9,7), (2,8,6), (3,7,5), (4,6,4)
	dunque S2 corrisponderebbe a 7+6+5+4=22.
Pertanto il metodo restituirebbe 17-22=-5.
            
*/
int Sudoku::metodo4()
{
    if(sudoku.empty()) return -1;
    
   	int s1=0,s2=0;
    for(int i=1;i<=9;i++){
    	for(int j=1;j<=i;j++){
		   	for(list<Cella>::iterator it = sudoku.begin(); it != sudoku.end(); it++)
			{
				if(it->getRiga()==i && j==it->getColonna()){
					s1+=it->getSimbolo();
					break;
				}
			}
    	}
    }
    	
    for(int i=1;i<=9;i++){
	   	for(list<Cella>::iterator it = sudoku.begin(); it != sudoku.end(); it++)
		{
			if(it->getRiga()==i && (10-i)==it->getColonna()){
				s2+=it->getSimbolo();
				break;
			}
		}
    }
    return s1-s2;
}


