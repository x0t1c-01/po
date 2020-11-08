
#include "MatriceOrdinaria.h"

/*
Restituire il numero di coordinate (i,j) nella lista di punti a cui sono associati valori differenti.

Se non sono presenti punti restituire -1.
Esempio: (0,0,3); (0,0,4); (1,0,4); (1,0,4); (2,1,1); (2,1,2); (2,1,3).
La coordinata (0,0) e la coordinata (2,1) hanno valori diversi, quindi il valore da restituire e` 2.

            
*/
int MatriceOrdinaria::metodo1()
{
    if(punti.empty())
 	   return -1;
	int cont=0;
	int mat[20][20];
	for(int i=0;i<20;i++){
		for(int j=0;j<20;j++){
			mat[i][j]=-1;
		}
	}
	for(list<Punto>::iterator it=punti.begin();it!=punti.end();it++){
		if( mat[it->getI()][it->getJ()]==-1 )
			mat[it->getI()][it->getJ()]=(it->getValore());
		else{
			if(mat[it->getI()][it->getJ()]!=(it->getValore()) && mat[it->getI()][it->getJ()]!=-2){
				cont++;
				mat[it->getI()][it->getJ()]=-2;
			}
		}
	}
	return cont;
		
}

/*
Restituire il massimo valore presente sulla diagonale principale.
Nel caso in cui una posizione contenga piu` di un valore per un punto prendere il valore piu` alto.

Se non sono presenti punti restituire -1.
            
*/
int MatriceOrdinaria::metodo2()
{
    if(punti.empty())
    	return -1;
	int mat[20][20];
	for(int i=0;i<20;i++){
		for(int j=0;j<20;j++){
			mat[i][j]=-1;
		}
	}
	int index;
	int max=INT_MIN,somma=0;
	for(list<Punto>::iterator it=punti.begin();it!=punti.end();it++){
		if( mat[it->getI()][it->getJ()]<(it->getValore()) )
			mat[it->getI()][it->getJ()]=(it->getValore());
	}
	for(int i=0;i<20;i++){
		for(int j=0;j<20;j++){
			if(i==j && mat[i][j]>max){
				max=mat[i][j];
				somma=mat[i][j];
			}
		}
	}
	return somma;

}

/*
Restituire l'indice i della riga con la somma piu` alta.
Nel caso in cui una o piu` righe abbiano la stessa somma, restituire la riga con l'indice piu` basso.
Nel caso in cui una posizione contenga piu` di un valore per un punto prendere il valore piu` alto.

Se non sono presenti punti restituire -1.
            
*/
int MatriceOrdinaria::metodo3()
{
    if(punti.empty())
    	return -1;
	int mat[20][20];
	for(int i=0;i<20;i++){
		for(int j=0;j<20;j++){
			mat[i][j]=-1;
		}
	}
	int index;
	int max=INT_MIN,somma=0;
	for(list<Punto>::iterator it=punti.begin();it!=punti.end();it++){
		if( mat[it->getI()][it->getJ()]<(it->getValore()) )
			mat[it->getI()][it->getJ()]=(it->getValore());
	}
	for(int i=0;i<20;i++){
		for(int j=0;j<20;j++){
			somma+=mat[i][j];
		}
		if(somma>max){
			max=somma;
			index=i;
		}
		somma=0;
	}
	return index;
	
}

/*
Sia TMP una lista temporanea di punti contenente tutti i punti della lista originale chiamata punti.
Ordinare TMP in accordo al seguente schema:
1) prima in ordine crescente in base all'indice i.
2) poi in ordine crescente in base all'indice j.
3) poi in ordine crescente in base al valore.

Restituire il valore del punto che si trova in prima posizione della lista cosi` ordinata.
Se non sono presenti punti restituire -1;
            
*/
int MatriceOrdinaria::metodo4()
{
    if(punti.empty())
    	return -1;
	vector<Punto> ordinati;
	for(list<Punto>::iterator it=punti.begin();it!=punti.end();it++)
		ordinati.push_back((*it));
	for(int i=0;i<ordinati.size();i++){
		for(int j=0;j<ordinati.size()-1;j++){
			if(ordinati[j].getI()>ordinati[j+1].getI())
				swap(ordinati[j],ordinati[j+1]);
		}
	}
	for(int i=0;i<ordinati.size();i++){
		for(int j=0;j<ordinati.size()-1;j++){
			if(ordinati[j].getJ()>ordinati[j+1].getJ())
				swap(ordinati[j],ordinati[j+1]);
		}
	}
	for(int i=0;i<ordinati.size();i++){
		for(int j=0;j<ordinati.size()-1;j++){
			if(ordinati[j].getValore()>ordinati[j+1].getValore())
				swap(ordinati[j],ordinati[j+1]);
		}
	}
	cout<<ordinati[0].getI()<<endl;
	cout<<ordinati[0].getJ()<<endl;
	return ordinati[0].getValore();
}


