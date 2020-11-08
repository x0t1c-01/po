#include "Concessionaria.h"

double Concessionaria::PrezzoScont(string targa){

    int prezzonuovo = 0;

    for(list<Veicolo>:: iterator it = Automobile.begin();it!= Automobile.end();it++){

        if(targa == it->getTarga()){
            prezzonuovo = it->getPrezzo();
            if(it.getTipo() == 0){
                if(it->getPrezzo() < 10000){
                    prezzonuovo = prezzonuovo - it->getPrezzo()*0.05;
                }
                if(it->getPrezzo()>10000 && it->getPrezzo()<20000){
                    prezzonuovo = prezzonuovo - it->getPrezzo()*0.1;
                }
            }
            if(it.getTipo() == 1){
                if(it->getPrezzo() < 7000){
                    prezzonuovo = prezzonuovo - it->getPrezzo()*0.03;
                }
                if(it->getPrezzo() > 7000 && it->getPrezzo()<15000){
                    prezzonuovo = prezzonuovo - it->getPrezzo()*0.075;
                }
            }
        }
    }
    return prezzonuovo;
}
