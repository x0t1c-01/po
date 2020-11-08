#ifndef UTENTE_H_
#define UTENTE_H_

#include<iostream>
using namespace std;

enum tipo { spedizione =0, pagamento, ricossione };
class Utente{
private:
    int numero;
    tipo tipologiaOperazione;

public:
    Utente(){int _numero = 0; tipo _tipologiaOperazione = 0}: numero(_numero),tipologiaOperazione(_tipologiaOperazione){}
    void getNumero()const {retrun numero};
    void setNumero(int x){numero=x;}
    void getTipologia() const{retrun tipologiaOperazione};
    void setTipologia(tipo a){tipologiaOperazione=a;}
};

#endif
