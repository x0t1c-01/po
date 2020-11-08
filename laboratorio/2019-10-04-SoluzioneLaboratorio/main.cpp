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

#include "VectorInt.h"
#include <cstdlib>
#include <cassert>
#include <climits>
using namespace std;

void aggiungiElementi(VectorInt& v) {
    int n = rand() % 10 + 1; //genera un numero tra 1 e 11
    for(int i = 0; i < n; i++) {
        v.push_back((rand() % 100) - 50); //genera numeri positivi e negativi
    }
}

void rimuoviElementi(VectorInt& v, int n) {
    int i = 0;
    while(v.size() > 0 && i < n) {
        v.pop_back();
        i++;
    }
}

void scambiaVettori(VectorInt& v1, VectorInt& v2) {
    VectorInt v3 = v1;
    v1 = v2;
    v2 = v3;
}

int massimo(VectorInt& v) {
    int max = INT_MIN;
    for(int i = 0; i < v.size(); i++) {
        if(v[i] > max)
            max = v[i];
    }
    return max;
}

int minimo(VectorInt& v) {
    int min = INT_MAX;
    for(int i = 0; i < v.size(); i++) {
        if(v[i] < min)
            min = v[i];
    }
    return min;
}

VectorInt sommaVettori(VectorInt& v1, VectorInt& v2) {
    assert(v1.size() == v2.size());
    VectorInt v3;
    for(int i = 0; i < v1.size(); i++) {
        v3.push_back(v1[i] + v2[i]);
    }
    return v3;
}

int prodottoScalare(VectorInt& v1, VectorInt& v2) {
    assert(v1.size() == v2.size());
    int ps = 0;
    for(int i = 0; i < v1.size(); i++) {
        ps += v1[i]*v2[i];
    }
    return ps;
}

bool opposto(VectorInt& v1, VectorInt& v2) {
    for(int i = 0; i < v1.size(); i++) {
        bool trovato = false;
        for(int j = 0; j < v2.size(); j++) {
            if(v1[i] == -v2[i])
                trovato = true;
        }
        if(!trovato)
            return false;
    }
    return true;
}

int sottosequenza(VectorInt& v) {
    int max = INT_MIN;
    int count = 0;
    for(int i = 0; i < v.size(); i++) {
        if(v[i] % 2 == 0)
            count++;
        else {
            if(count > max)
                max = count;
            count = 0;
        }
    }
    if(count > max)
        max = count;
    return max;
};

int frequente(VectorInt& v) {
    assert(v.size() > 0);
    int max = INT_MIN;
    int num = 0;
    for(int i = 0; i < v.size(); i++) {
        int count = 0;
        for(int j = 0; j < v.size(); j++) {
            if(v[i]==v[j]) {
                count++;
            }
        }
        if(count > max) {
            max = count;
            num = v[i];
        }
    }
    return num;
}

int main() {
    srand(time(0));
    //Qui si possono testare le varie funzioni.
}
