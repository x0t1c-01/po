/*
Utilizzando la classe VectorInt vista a lezione implementare le seguenti funzioni:

1.	void aggiungiElementi(VectorInt& v); genera un numero casuale di numeri interi e li inserisce all’interno di v.

2.	void rimuoviElementi(VectorInt& v, int n); elimina gli ultimi n elementi dal vettore.

3.	void scambiaVettori(VectorInt& v1, VectorInt& v2); scambia il contenuto dei vettori v1 e v2.

4.	int massimo(VectorInt& v); restituisce il numero massimo in v. Se v è vuoto restituisce INT_MIN.

5.	int minimo(VectorInt& v); restituisce il numero minimo in v. Se v è vuoto restituisce INT_MAX.

6.	VectorInt sommaVettori(VectorInt& v1, VectorInt& v2); crea (e restituisce) un nuovo vettore sommando il contenuto dei vettori v1 e v2. Si può assumere che v1 e v2 abbiano la stessa dimensione. Esempio: v1=(0,2,4), v2=(3,4,1) si deve restituire (3,6,5).

7.	int prodottoScalare(VectorInt& v1, VectorInt& v2); calcola il prodotto scalare tra v1 e v2. Si può assumere che v1 e v2 abbiano la stessa dimensione. Si ricorda che il prodotto scalare tra due vettori (u1, u2, u3, …, uN) e (k1, k2, k3, …, kN) si calcola come u1*k1 + u2*k2 + u3*k3 + … + uN*kN.

8.	bool opposto(VectorInt& v1, VectorInt& v2); restituisce true se per ogni numero N in v1, il suo opposto -N è in v2.

9.	int sottosequenza(VectorInt& v); restituisce la dimensione della più grande sottosequenza di numeri pari in v.

10.	int frequente(VectorInt& v); restituisce il numero che occorre più spesso in v, in caso di parità, restituisce il primo. Si può assumere che v contenga almeno un elemento.
*/

#include<iostream>
#include"VectorInt"
#include<time.h>
using namespace std;

void aggiungiElementi(VectorInt& v){
    int n=rand() %10+1;
    for(int i=0;i<n;i++){
        v.push_back((rand()100)-50);
    }
}

void rimuoviElementi(VectorInt& v, int n){
    int i=0;
    while(v.size()>0 && i<n){
        v.pop_back();
        i++;
    }
}

void scambiaVettori(VectorInt& v1, VectorInt& v2){
    VectorInt v3=v1;
    v1=v2;
    v2=v3;
}

int massimo(VectorInt& v){
    int valmax=INT_MIN;
    for(int i=0;i<v.size();i++){
        if(v[i]>valmax){
            valmax=v[i];
        }
    }
    return valmax;
}

int minimo(VectorInt& v){
    int valmin=INT_MAX;
    for(int i=0;i<v.size();i++){
        if(v[i]<valmin){
            valmax=v[i];
        }
    }
    return valmin;
}


VectorInt sommaVettori(VectorInt& v1, VectorInt& v2){
    assert(v1.size()==v2.size()); //???????????????????????????????????????????????????????????????????????????????
    VectorInt v3;
    for(int i=0;i<v1.size();i++){
        v3.push_back(v2[i]+v1[i]);
    }

    return v3;
}

int prodottoScalare(VectorInt& v1, VectorInt& v2){
    assert(v1.size()==v2.size());
    int prod=0;
    for(int i=0;i<v1.size();i++){
        prod+=v1[i]*v2[i];
    }

    return prod;
}

bool opposto(VectorInt& v1, VectorInt& v2){
    for(int i=0;i<v1.size();i++){
        bool trovato =false;
            for(int i=0;i<v2.size();i++){
                if(v1[i]== -v2[j])
                    trovato=true;
            }
        if(!trovato)
            return false;
    }
    return true;
}

int sottosequenza(VectorInt& v){
    int cont=0;
    int sq=INT_MIN;
    for(int i=0;i<v.size();i++){
        if(v[i]%2==0)
            cont++;
        else{
            if(cont>sq)
                sq=cont
            cont=0;
        }
    }
    if(cont>sq)
        sq=cont;

    return sq;

}

int frequente(VectorInt& v){
    assert(v.size()>0);

    int cont=0;
    int nummax=0;
    int contnummax=INT_MIN;
    for(int i=0;i<v.size();i++){
        cont=0;
        for(int j=0;j<v.size();i++){
            if(v[i]==v[j])
                cont++
        }
    if(cont>contnummax){
        contnummax=cont;
        nummax=v[i];
        }
    }

    return nummax;
}



int main(){

return 0;
}
