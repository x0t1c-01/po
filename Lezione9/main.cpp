#include "Professore.h"
#include "Studente.h"
#include "CodaPersone.h"

int main(){
	Persona* p1=new Studente;
	p1->setNome("Mario");
	p1->setCognome("Rossi");
	Persona* p2=new Professore;
	p2->setNome("Luca");
	p2->setCognome("Bianchi");

	CodaPersone persone;
	persone.push(p1);
	persone.push(p2);
	persone.print();
	
	//Non valido p1 è una Persona -> ne riparleremo prossimamente, quando tratteremo il polimorfismo
	//p1->setIsee(15);
	
	Studente* p3=dynamic_cast<Studente*>(p1);
	p3->setIsee(15);
	persone.print();
		
	delete p1;
	delete p2;
	return 0;
}
