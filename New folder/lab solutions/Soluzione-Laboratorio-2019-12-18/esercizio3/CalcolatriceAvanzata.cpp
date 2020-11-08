
#include "CalcolatriceAvanzata.h"

/*
Sia (A,B,C) la prima tripla nella lista e sia S=A+B+C.
Restituire il numero primo piu` grande tra i numeri primi minori di S.
Un numero P e` primo se e` > 1 ed e` divisibile solo per 1 e per P.

Se non sono presenti triple di numeri o se non esiste nessun primo minore di S, restituire -1.
            
*/
int primo(int n) {
    if(n <= 1)
        return false;
    for(int i = 2; i < n; i++)
        if(n%i==0)
            return false;
    return true;
}

int CalcolatriceAvanzata::metodo1()
{
    if(numeri.empty())
        return -1;
    int s = numeri.front().getNum1()+numeri.front().getNum2()+numeri.front().getNum3();
    for(int i = s-1; i >= 0; i--)
        if(primo(i))
            return i;
    return -1;
}

/*
Sia N il numero piu` grande  di cinque cifre costruibile concatenando cinque num1 della lista.
Sia M il numero piu` piccolo di cinque cifre costruibile concatenando cinque num2 della lista.
(Si assuma che num1 e num2 siano sempre compresi tra 0 e 9.)
Restituire N-M.

Se la lista ha meno di 5 elementi restituire -1.

Esempio:
Sia la lista di triple composta da (1,2,3) (2,3,4) (7,7,9) (4,5,3) (8,1,2) (1,1,1).
N = 87421
M = 11235
            
*/
bool rev(const int& a, const int& b) {
    return a > b;
}

int createNum(const list<int>& l) {
    int n = 0;
    auto it = l.begin();        
    for(int i = 5; i > 0; i--) {
        n += *it * pow(10,i-1);
        ++it;
    }
    return n;
}

int CalcolatriceAvanzata::metodo2()
{
    if(numeri.size()<5)
        return -1;
    
    list<int> num1;
    list<int> num2;
    for(auto n : numeri) {
        num1.push_back(n.getNum1());
        num2.push_back(n.getNum2());
    }
    num1.sort(rev);
    num2.sort();
    int N = createNum(num1);
    int M = createNum(num2);
    
    return N-M;
}

/*
Sia LD la lista di triple duplicate.
Una tripla e` considerata duplicata se i primi due numeri sono uguali.
Sia M1 la media dei num1 degli elementi in LD.
Sia M2 la media dei num2 degli elementi in LD.
(Per le medie si usi la divisione intera.)
Restituire M1 - M2.

Se la lista e` vuota o non ha duplicati restituire -1.

Esempio:
(2,1,4) (2,1,6) (4,3,7) (4,3,7) (3,4,8) (5,6,2) (6,5,2)
Le triple duplicate sono (2,1,_) e (4,3,_).
La media dei num1 e` pari a 3.
La media dei num2 e` pari a 2.
Quindi il metodo deve restituire 1.
            
*/
int media(const list<TriplaNumeri>& l, bool num1) {
    if(l.empty())
        return INT_MAX;
    int somma = 0;
    for(auto n : l)
        if(num1)
            somma+=n.getNum1();
        else
            somma+=n.getNum2();            
    return somma/l.size();
}

bool esiste(const list<TriplaNumeri>& l, TriplaNumeri t) {
    for(auto n : l)
        if(n.getNum1() == t.getNum1() && n.getNum2() == t.getNum2())
            return true;
    return false;
}

list<TriplaNumeri> duplicate(const list<TriplaNumeri>& numeri) {
    list<TriplaNumeri> l;
    for(auto& n1 : numeri) {
        for(auto& n2 : numeri) {
            if(&n1 != &n2 && n1.getNum1() == n2.getNum1() && n1.getNum2() == n2.getNum2())
                if(!esiste(l, n1))
                    l.push_back(n1);
        }
    }
    return l;
}

int CalcolatriceAvanzata::metodo3()
{
    list<TriplaNumeri> d = duplicate(numeri);
    if(d.empty())
        return -1;
    
    int M1 = media(d, true);
    int M2 = media(d, false);
    return M1-M2;
}

/*
Sia MAX il numero piu` grande  tra tutti i numeri presenti nella lista.
Sia MIN il numero piu` piccolo tra tutti i numeri presenti nella lista.

Restituire MAX - MIN se MAX e MIN     sono coprimi.
Restituire MIN - MAX se MAX e MIN non sono coprimi.

Si ricorda che due numeri N1 ed N2 sono coprimi se e solo se N1 e N2 non hanno alcun divisore comune eccetto 1 o -1.

Se la lista e` vuota restituire -1.
            
*/
bool coprimi(int min, int max) {
    while(min != 0) {
        int r = max % min;
        max = min;
        min = r;
    }
    return max == 1;
}

int CalcolatriceAvanzata::metodo4()
{
    if(numeri.empty())
        return -1;
    
    int massimo = INT_MIN;
    int minimo = INT_MAX;
    for(auto n : numeri) {
        massimo = max(massimo, max(n.getNum1(),max(n.getNum2(),n.getNum3())));
        minimo = min(minimo, min(n.getNum1(),min(n.getNum2(),n.getNum3())));        
    }
    if(coprimi(minimo, massimo))
        return massimo-minimo;
    return minimo-massimo;
}


