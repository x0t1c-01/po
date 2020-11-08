#include"Supermercato.h"

void Supermercato:: aggiungiProdotto(Prodotto* p){
    prodotti.push_back(p);
}

void Supermercato::rimuoviProdotto(Prodotto* p){
    prodotti.remove(p);
}

void Supermercato::stampaInventario() const{
    cout<<"prodotti disponibili:"<<endl;
    for(auto it=prodotti.begin();it!=prodotti.end();it++){
        cout<<**it<<endl;
    }
}

bool ordina(prodotto p1,prodotto p2){
    return p1.getPrezzo()<p2.getPrezzo();
}

void Supermercato::prodottiEconomici(int n) const{
    prodotti.sort(ordina);
    int i=1;
    for(auto it=prodotti.begin();it!=prodotti.end();it++){
        if(i<=n)
            cout<<**it<<endl;
        else
            break;
    }

}
