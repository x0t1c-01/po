#include "GestoreComputers.h"
#include"Computer.h"
using namespace std;
int main() {

    Computer A("hp","hassan",200, NETBOOK,"Bs");
    Computer B("dell","mostafa",200, NETBOOK,"Css");
    Computer C("lenovo","mimo",300, NETBOOK,"ds");
    Computer D("xaomi","mostafa",600, NETBOOK,"Ss");
    Computer E("mahmoud","mimo",540, NETBOOK,"aS");
    Computer F("mahmoud","hassan",300, NETBOOK,"ss");

    GestoreComputers G;
    G.aggiungi(A);
    G.aggiungi(B);
    G.aggiungi(C);
    G.aggiungi(D);
    G.aggiungi(F);
    G.aggiungi(E);

    cout<<G.metodo1()<<endl;
    return 0;
}
