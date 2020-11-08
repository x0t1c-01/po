#ifndef POSTA_H_
#define POSTA_H_

#include "Utente.h"
#include<list>

class Posta{
private:
    list<Utente> utenti;

public:
    void aggiungiUtente(int tipologiaOperazione);
    Utente prossimoUtente();
    void stampaUtentiInCoda() const;
    void stampaUtenti(int tipologiaOperazione) const;
    void reset();
};
#endif
