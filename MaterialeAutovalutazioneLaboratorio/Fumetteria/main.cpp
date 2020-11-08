#include "Fumetteria.h"
int main()
{
    Fumetto a("sksk","ommak",100,KODOMO,"sk2sk");
    Fumetto b("ss","abook",200,KODOMO,"sksd2sk");
    Fumetto c("skadsk","ommak",300,SPOKON,"sksk");
    Fumetto d("skdsadsk","abook",300,KODOMO,"toto");
    Fumetto e("skddsk","ommak",400,KODOMO,"toto");
    Fumetto f("sk2sk","5ltak",10,KODOMO,"sksd2sk");
    Fumetto g("sksd2sk","5ltak",100,KODOMO,"sk3sk");
    Fumetteria z;
    z.aggiungi(a);
    z.aggiungi(b);
    z.aggiungi(c);
    z.aggiungi(d);
    z.aggiungi(e);
    z.aggiungi(f);
    z.aggiungi(g);


    cout<<z.metodo1()<<endl;
    cout<<z.metodo2()<<endl;
    cout<<z.metodo3()<<endl;
    cout<<z.metodo4()<<endl;
}
