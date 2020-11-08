#include"Posta.h"

void Posta:: aggiungiUtente(int tipologiaOperazione){

    for(auto it=utenti.begin();it!=utenti.end();++it){
        Utente* p= *it;
        if(p->getTipologia==tipologiaOperazione){
            
        }
    }
}
