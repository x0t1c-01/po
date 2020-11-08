#include"AgenziaViaggi.h"
int main(){
	Viaggio A("Londra",EUROPA,3000,50,100);
	Viaggio B("Tokyo",ASIA,10000,1000,200); 
	Viaggio C("New York",AMERICA,9000,2000,100);
	Viaggio D("New York",AMERICA,9000,1500,130);
	AgenziaViaggi Z;
	Z.aggiungi(A);
	Z.aggiungi(B);
	Z.aggiungi(C);
	Z.aggiungi(D);
	cout<<Z.metodo4()<<endl;
	return 0;
}
