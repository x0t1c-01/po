
#include "Mobilificio.h"

/*
Sia X la media dei prezzi di tutti i mobili. Determinare il massimo
prezzo fra quelli che hanno un prezzo minore o uguale a X.

Per il calcolo della media utilizzare la divisione intera.

Se non sono presenti mobili, restituire -1.

*/
int Mobilificio::metodo1()
{
    if(mobili.empty())
        return -1;
    int somma=0;
    for(auto it=mobili.begin();it!=mobili.end();it++){
        somma+=it->getPrezzo();
    }
    int media=somma/mobili.size();
        int max=-1;
        for(auto it=mobili.begin();it!=mobili.end();it++){
            if(it->getPrezzo()<media){
                if(it->getPrezzo()>=max)
                    max=it->getPrezzo();
            }
        }
        return max;
}
/*
Per ogni produttore P sia M(P) il prezzo medio dei mobili prodotti da P.
Un produttore si dice economico se produce solo mobili che costano meno
del prezzo medio M(P) di ogni *altro* produttore.
Attenzione: Il prezzo dei prodotti del produttore economico E non e' mai confrontato
            con la media M(E) (cioe' e' confrontato con tutti tranne che con se stesso).

Il metodo restituisce il numero di mobili prodotti dal *primo* produttore economico della lista.

Per il calcolo della media utilizzare la divisione intera.

Se non sono presenti mobili oppure se nessun produttore verifica la condizione oppure se c'e' un solo produttore, restituire -1.


*/
int Mobilificio::metodo2()
{
    if(mobili.empty())
        return -1;

    vector <string> p;
    for(auto it=mobili.begin();it!=mobili.end();it++){
        if(find(p.begin(),p.end(),(it->getProduttore()))==p.end()){
            p.push_back((it->getProduttore()));
        }
    }

    if(p.size()<2)
        return -1;

    vector<int> mp;
    for(int i=0;i<p.size();i++){
        int somma=0;
        int cont=0;
        for(auto it=mobili.begin();it!=mobili.end();it++){
            if(p[i]==it->getProduttore()){
                somma+=it->getPrezzo();
                cont++;
            }
        }
        mp.push_back(somma/cont);
    }
    bool cond=true;
    int cont=0;
        for(int i=0;i<p.size();i++){
         cond=true;
         cont=0;
            for(auto it : mobili){
                if(it.getProduttore()==p[i]){
                    for(int j=0;j<mp.size();j++){
                        if(i!=j)
                            if(it.getPrezzo()>mp[j])
                                cond=false;
                    }
                    cont++;
            }
        }
        if(cond)
        {
            return cont;
        }
    }
    if(!cond)
return -1;
}



/*
Il metodo restituisce la differenza tra il numero di produttori che producono solo TAVOLI e il numero di produttori che producono solo SEDIE.

Nel caso in cui non siano presenti mobili nel mobilificio, restituire -1.

*/
int Mobilificio::metodo3()
{
    if(mobili.empty())
        return -1;

    vector<string> pt;
    vector<string> ps;
    for(auto it=mobili.begin();it!=mobili.end();it++){
        if(find(mobili.begin(),mobili.end(),(it->getProduttore()))==mobili.end()){
            if(it->getTipo()==0)
                pt.push_back(it->getProduttore());
        }
    }
    for(auto it=mobili.begin();it!=mobili.end();it++){
        if(find(mobili.begin(),mobili.end(),(it->getProduttore()))==mobili.end()){
            if(it->getTipo()==1)
                ps.push_back(it->getProduttore());
        }
    }
    return pt.size()-ps.size();
}

/*
Data la seguente definizione:
Un produttore P1 collabora con un produttore P2 se:
- P1 produce un mobile in collaborazione con P2, oppure
- P1 produce un mobile in collaborazione con P3 e P3 collabora con P2.

Il metodo deve restituire il numero di produttori che collabora con l'ultimo della lista.

Nel caso in cui non ci siano mobili restituisce -1.

Esempio di collaborazione.

Supponiamo che:
- P1 realizza il mobile S con la collaborazione di P2.
- P2 realizza il mobile S1 con la collaborazione di P3.
- P3 realizza il mobile S2 con la collaborazione di P4.

P1 collabora con P2, con P3 e con P4.
P2 collabora con P3 e con P4.
P3 collabora con P4.

Se P1 fosse l'ultimo produttore della lista il metodo restituirebbe 3.
Se P4 fosse l'ultimo produttore della lista il metodo restituirebbe 0.

*/
int Mobilificio::numCollaboratori(string nomeUltimo){
    vector<string> col;
    for(auto it : mobili){
        if(it.getProduttore()==nomeUltimo)
            if(find(col.begin(),col.end(),it.getCollaboratore())==col.end())
                col.push_back(it.getCollaboratore());
    }
    for(int i=0;i<col.size();i++){
        for(auto it : mobili){
            if(col[i]==it.getProduttore())
                if(find(col.begin(),col.end(),it.getCollaboratore())==col.end())
                    col.push_back(it.getCollaboratore());
        }
    }
    return col.size();
}
int Mobilificio::metodo4()
{
    if(mobili.empty())
        return -1;
    return numCollaboratori(mobili.back().getProduttore());
}
