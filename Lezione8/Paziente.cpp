#include "Paziente.h"

Paziente::Paziente() : Persona(), codice(BIANCO) {}

Paziente::Paziente(const string& n, CodiceUrgenza c) : Persona(), codice(c) { 
	setNome(n);
	//nome=n; //perchè nome è protected
}

Paziente::Paziente(const string& n, const string& c, const string& cf, CodiceUrgenza co): Persona(n,c,cf), codice(co){} 

CodiceUrgenza Paziente::getCodice() const { return codice; }

void Paziente::setCodice(CodiceUrgenza codice) { this->codice = codice; }

void Paziente::stampa() const {
	Persona::stampa();
	switch(codice){
		case 0:
			cout<<"BIANCO";
			break;
		case 1:
			cout<<"VERDE";
			break;
		case 2:
			cout<<"GIALLO";
			break;
		default:
			cout<<"ROSSO";
			break;
	}
	cout<<endl;
}

bool Paziente::operator<=(const Paziente& p) const { return codice <= p.codice; }