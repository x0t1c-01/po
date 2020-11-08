#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include "Automobile.h"
using namespace std;

bool ordina(Automobile a1, Automobile a2){
    if(a1.getPrezzo()>a2.getPrezzo())
        return true;

    if(a1.getPrezzo()<a2.getPrezzo())
        return false;

    if(a1.getPrezzo()==a2.getPrezzo())
        return  a1.getAnnoprod()>a2.getAnnoprod();

    }



int main(){
    //es1
    list<Automobile> auto;
    //es2,3
    auto.sort(ordina);
    //es4
    int somma=0;
    for(list<auto>::iterator it=auto.begin();it!=auto.end();it++){
        somma+=it->getPrezzo();
    }
    int media;
    media=somma/auto.size();
    //????????????????????????????????????????????????????????????????????????????


    //es5,es6
    vector <string> marche;
    for(list<auto>::iterator it=auto.begin();it!=auto.end();it++){
        if(find(auto.begin(),auto.end(),it->getMarca())==marche.end())
            marche.push_back(it->getMarca());
    }
    int cont=0,cont2=0,cont3=0,cont4=0;
    for(int i=0;i<marche.size();i++){
        cont=0;
        cont2=0;
        for(list<auto>::iterator it=auto.begin();it!=auto.end();it++){
            if(it->getMarca()==marche[i])
                cont++;
                if(it->getPrezzo()>media)
                    cont2++;
        }
            if(cont==cont2)
                cont3++;
            if(cont>0 && cont2==0)
                cont4++;
    }

    return 0;
}
