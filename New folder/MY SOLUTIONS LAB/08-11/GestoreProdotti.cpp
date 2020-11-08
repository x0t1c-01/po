#include"GestoreProdotti.h"


bool GestoreProdotti::aggiungiProdotto(int id, string descrizione , float prezzo)
{

    for(auto it=prodottii.begin();it!=prodottii.end();++it){
        prodotto* p =*it;
        if(p->getId()==id)
            return false;
    }
    prodottii.push_back(new prodotto(id,descrizione,prezzo));
    return true;
}

bool GestoreProdotti::modificaProdotto(int id, string descrizione, float prezzo){
    for(auto it=prodotti.begin();it!=prodotti.end();++it){
        prodotto* p= *it;
        if(p->getId()==id){
            p->setDescrizione(descrizione);
            p->setPrezzo(prezzo);
            return true;
        }
    }
    return false;

}

Prodotto* GestoreProdotti::getProdotto(int id) const{
    for(auto it=prodotti.begin();it!=prodotti.end();++it){
        prodotto* p= *it;
        if(p->getId()==id)
            return p;
    }
return nullptr;
}
