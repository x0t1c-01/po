
#include "CalcolatriceAvanzata.h"

/*
Un numero P e` primo se e` > 1 ed e` divisibile solo per 1 e per P.
Una tripla di numeri C=(num1,num2,num3) e` bilanciata se esattamente uno tra num1 e num2 e` primo.
Restituire il numero di triple bilanciate presenti nella lista.

Se non sono presenti triple di numeri, restituire -1.

*/
bool CalcolatriceAvanzata::primo(int n){
    for(int i=2;i<n/2;i++){
        if(n%i==0)
            return false;
    }
    return true;
}

int CalcolatriceAvanzata::metodo1(){
if(numeri.empty())
    return -1;

int cont2=0;
    for(auto it=numeri.begin();it!=numeri.end();it++){
        int cont=0;
        if(primo(it->getNum1()))
            cont++;
            if(primo(it->getNum2()))
                cont++;
                if(primo(it->getNum3()))
                    cont++;

    if(cont==1)
        cont2++;
    }
return cont2;
}

/*
Restituire il num1 della terza tripla della lista ordinata nel seguente modo:
- Prima tutte le triple con il valore piu` alto di num1.
- A parita` di valore del num1, le triple con il valore piu` alto di num2.
- A parita` di valore del num2, le triple con il valore piu` alto di num3.

Se la lista ha meno di 3 elementi restituire -1.
ATTENZIONE: NON MODIFICARE la lista di numeri ma creare una copia temporanea.

*/

bool compare(const TriplaNumeri& i,const TriplaNumeri& j){
    if(i.getNum1()>j.getNum1())
        return true;
    if(i.getNum1()==j.getNum1()){
        if(i.getNum2()>j.getNum2())
            return true;
        if(i.getNum2()==j.getNum2())
            return  i.getNum3()>j.getNum3();
    }
    return false;

}
int CalcolatriceAvanzata::metodo2()
{
    if(numeri.size()<3)
        return -1;

    list<TriplaNumeri> tmp = numeri;

     tmp.sort(compare);
     auto it=tmp.begin();
     advance(it,2);

     return it->getNum1();
}

/*
Sia LD la lista di triple duplicate.
Una tripla e` considerata duplicata se i primi due numeri sono uguali.
Restituire il massimo della somma tra num1 e num2 degli elementi in LD.

Esempio:
(1,2,4) (1,2,6) (3,4,7) (3,4,7) (3,4,8) (5,6,2) (6,5,2)
Le triple duplicate sono (1,2,_) e (3,4,_).
La somma di num1 e num2 della prima tripla e` pari a 3.
La somma di num1 e num2 della seconda tripla a 7.
Quindi il metodo deve restituire 7.

Se la lista e` vuota o non ha duplicati restituire -1.

*/
int CalcolatriceAvanzata::metodo3()
{
    if(numeri.empty())
        return -1;

    int max=-1;
    int cont2=0;
    for(auto it=numeri.begin();it!=numeri.end();it++){
        int cont=0,somma=0;
        for(auto it2=numeri.begin();it2!=numeri.end();it2++){
            if((it->getNum1()==it2->getNum1())&&(it->getNum2()==it2->getNum2()))
                cont++;
        }
        if(cont>1){
            somma+=it->getNum1()+it->getNum2();
            cont2++;

            if(somma>max)
                max=somma;
        }
}
if(cont2==0)
    return -1;

    return max;
}

/*
Sia P il primo numero a 4 cifre della lista (considerando solo il num3).

Sia PMAX il numero max che e` possibile comporre usando tutte le cifre di P.
Sia PMIN il numero min che e` possibile comporre usando tutte le cifre di P.

Restituire PMAX-PMIN.

Ad esempio, sia P = 1243, allora PMAX=4321 e PMIN=1234.

Se la lista e` vuota o se non ha numeri a 4 cifre restituire -1.

*/
int CalcolatriceAvanzata::metodo4()
{
    if(numeri.empty())
        return -1;
    int a[4];
    int dim=0;
    for(auto it=numeri.begin();it!=numeri.end();it++){
        if(((it->getNum3())>999)&&((it->getNum3())<10000)){
            int x=it->getNum3();
            while(x>0){
                a[dim++]=x%10;
                x/=10;
            }
            for(int i=0;i<dim-1;i++){
                for(int j=0;j<dim-i-1;i++){
                    if(a[j]<a[i])
                        swap(a[i],a[j]);
                }
            }
            /*for(int i=0;i<4;i++){
                cout<<a[i]<<" ";
            }
            cout<<endl;*/

            int pmax=0;
            int pmin=0;
            int e=1000;
            for(int i=0;i<4;i++){
                pmax+=a[i]*e;
                e/=10;
            }
            int r=1000;
            for(int i=3;i>=0;i--){
                pmin+=a[i]*r;
                r/=10;
            }
            /*cout<<endl;
            cout<<pmax<<"  "<<pmin;
            */
            return pmax-pmin;
        }
    }

    return -1;
}
