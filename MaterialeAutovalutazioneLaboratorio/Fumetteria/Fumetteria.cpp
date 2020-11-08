
#include "Fumetteria.h"

/*
Sia A l'autore che ha scritto piu' fumetti nella fumetteria.
(Se piu' autori hanno questa proprieta', prendere il primo
di questi che compare nella fumetteria.)
Restituire la somma dei prezzi di tutti i fumetti scritti da A.

Se non sono presenti fumetti nella fumetteria, restituire -1.

*/
int Fumetteria::metodo1()
{
    if(fumetteria.empty())
        return -1;

    vector<string> autori;
    vector<int> num;
        for(auto it=fumetteria.begin();it!=fumetteria.end();it++){
            if(find(fumetteria.begin(),fumetteria.end(),(it->getAutore()))==fumetteria.end())
                autori.push_back((it->getAutore()));
        }

        for(int i=0;i<autori.size();i++){
            int cont=0;
            for(auto it=fumetteria.begin();it!=fumetteria.end();it++){
                if(autori[i]==(it->getAutore()))
                    cont++;
            }
            num.push_back(cont);
        }
        int max=-1;
        int k=0;
        for(int i=0;i<num.size();i++){
            if(num[i]>max){
                 k=i;
                max=num[i];
            }

        }

        int somma=0;
        for(auto it=fumetteria.begin();it!=fumetteria.end();it++){
            if(autori[k]==(it->getAutore())){
                somma+=(it->getPrezzo());
            }
        }

    return somma;
}

/*
Determinare la mediana dei fumetti ottenuta considerando la seguente relazione d'ordine:

Un fumetto F1 precede un fumetto F2 se il prezzo di F1 e' minore del prezzo di F2 e a parita' di prezzo, il tipo di F1 precede il tipo di F2 (KODOMO precede SPOKON precede GEKIGA).

Restituire il prezzo del fumetto che si trova in corrispondenza della mediana.

Nel caso in cui non ci siano fumetti presenti nella fumetteria, restituire -1.

NOTA BENE: calcolare mediana nel seguente modo: dopo aver ordinato gli oggetti in modo crescente,
si prende quello presente nel mezzo (utilizzare la divisione intera: size/2).

*/

bool compare(Fumetto& a1,Fumetto& a2){
    if(a1.getPrezzo()>a2.getPrezzo())
        return true;
        if(a1.getPrezzo()==a2.getPrezzo())
            if(a1.getTipo()>a2.getTipo())
                return true;
        return false;
}
int Fumetteria::metodo2()
{
    if(fumetteria.empty())
        return -1;
    fumetteria.sort(compare);
    auto it=fumetteria.begin();
    int a=fumetteria.size()/2;
    advance(it,a);
    return it->getPrezzo();

}

/*
Data la seguente definizione:
Un fumetto F1 fa riferimento ad un fumetto F2 se:
- F1 fa riferimento a F2, oppure
- F1 fa riferimento a F3 e F3 fa riferimento a F2.

Sia F il fumetto con il piu' alto numero di riferimenti, il metodo deve restituire il numero di fumetti a cui F fa riferimento.

Nel caso in cui non ci siano fumetti nella fumetteria restituisce -1.

*/
int Fumetteria::num(string titolo){
    vector<string> s;
    for(auto it : fumetteria){
        if(titolo==it.getTitolo()){
            if(find(s.begin(),s.end(),it.getRiferimentoA())==s.end())
                s.push_back(it.getRiferimentoA());
        }
    }
    for(int i=0;i<s.size();i++){
        for(auto it : fumetteria){
            if(s[i]==it.getTitolo())
                if(find(s.begin(),s.end(),it.getRiferimentoA())==s.end())
                    s.push_back(it.getRiferimentoA());
        }
    }
    return s.size();
}

int Fumetteria::metodo3(){
    if(fumetteria.empty())
        return -1;

    vector<int> nmax;
   for(auto it : fumetteria){
        nmax.push_back(num(it.getTitolo()));
}
int max=INT8_MIN;
int po=-1;
for(int i=0;i<nmax.size();i++){
    if(nmax[i]>max){
        max=nmax[i];
    }
}
return nmax[max];
}
/*
Data la seguente definizione:
Un fumetto F1 fa riferimento ad un fumetto F2 se:
- F1 fa riferimento a F2, oppure
- F1 fa riferimento a F3 e F3 fa riferimento a F2.

Sia F il primo fumetto della fumetteria, il metodo deve restituire il numero di fumetti con cui F fa riferimento.

Nel caso in cui non ci siano fumetti nella fumetteria restituisce -1.

*/
    int Fumetteria::rif(string g){
        vector<string> riferimenti;
        for(auto it:fumetteria){
            if(it.getTitolo()==g){
            if(find(riferimenti.begin(),riferimenti.end(),it.getRiferimentoA())==riferimenti.end()){
                riferimenti.push_back(it.getRiferimentoA());
            }
        }
    }
        for(int i=0;i<riferimenti.size();i++){
            for(auto it:fumetteria){
                if(it.getTitolo()==riferimenti[i]){
                if(find(riferimenti.begin(),riferimenti.end(),it.getRiferimentoA())==riferimenti.end()){
                    riferimenti.push_back(it.getRiferimentoA());
                }
            }
            }
        }
        return riferimenti.size();
    }
int Fumetteria::metodo4()
{
    auto it=fumetteria.begin();
    return rif(it.getTitolo());
}
