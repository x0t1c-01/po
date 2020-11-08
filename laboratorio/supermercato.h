#ifndef SUPERMERCATO_H
#define SUPERMERCATO_H
#include<list>
#include<climits>
#include"Prodotto.h"
class Supermercato{

private:
    list <Prodotto*> prodotti;
public:
    void aggiungiProdotto(Prodotto*);
    void rimuoviProdotto(Prodotto*);
    void stampaInventario() const;
    void prodottiEconomici(int n) const;
    void svuota();

};

void Supermercato::aggiungiProdotto(Prodotto* p){
    prodotti.push_back(p);
}

void Supermercato::rimuoviProdotto(Prodotto* p){
    prodotti.remove(p);
}
void Supermercato::stampaInventario(){
    for(auto it: prodotti){
        cout<<**it<<endl;
    }
}
bool Supermercato::ordina(Prodotto* p1,Prodotto* p2){
    return p1.getPrezzo()<p2.getPrezzo();
}
void Supermercato::prodottiEconomici(int n) const{
    list<Prodotto*> economici;
    for(auto it:prodotti){
        economici.push_back(*it);
    }
    eonomici.sort(ordina);
    int cont=0;
    for(auto it : economici){
        cout<<**it<<endl;
        if(cont==n)
            break;
        cont++;
    }
}
void Supermercato::svuota() {
    prodotti.clear();
}
#endif
