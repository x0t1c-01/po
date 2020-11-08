#include<iostream>
#include"Paziente.h"
#include<algorithm>
#include<vector>

using namespace std;

bool precede(PAziente* p1, Paziente p2){
    if(p1->getCodice()==1 && p2->getCodice() != 1)
        return true;
    if(p1->getCodice()!=1 && p2->getCodice() == 1)
        return false;
    if(p1->getCodice()==1 && p2->getCodice() == 1)
        return p1->getNumero() < p2->getNumero();

        if(p1->getCodice()==2 && p2->getCodice() != 2)
            return true;
        if(p1->getCodice()!=2 && p2->getCodice() == 2)
            return false;
        if(p1->getCodice()==2 && p2->getCodice() == 2)
            return p1->getEta() < p2->getEta();

        return p1->getTipologia() < p2->getTipologia();
    }

bool nonprecede(Paziente* p1, Paziente* p2){
    return !precede(p1,p2);
}

class Laboratorio : private vector<Paziente*> {

public:
        void add(Paziente* p){
            //sort(begin(),end(), precede);
            for(auto it=begin();it!=end()++it){
                if(precede(p,*it)){
                    insert(it,p);
                    return;
                }
            }
                push_back(p);
        }

        Paziente * next() const{
            return front();
        }
        void remove(){
            pop_back();
        }
        unsigned int size() const{
            return vector<Paziente*>::size();
        }





}
