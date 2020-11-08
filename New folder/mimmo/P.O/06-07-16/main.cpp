#include"Cinema.h"
int main() 
{
	Film A("Fast",2011,100,"Luca",ANIMAZIONE);
	Film B("Orbit",2011,50,"Ara",COMICO);
	Film C("Harry Potter",2011,110,"Luca",HORROR);
	Film D("Shrek",2011,200,"Giulia",ANIMAZIONE);
	Cinema Z;
	Z.aggiungi(A);
	Z.aggiungi(B);
	Z.aggiungi(C);
	Z.aggiungi(D);
	cout<<Z.metodo4()<<endl;
    return 0;
}
