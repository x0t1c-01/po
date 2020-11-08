#include "Persona.h"

Persona::Persona(): codiceFiscale(""), nome(""), cognome("") {
	//cout<<"Sto invocando il costruttore di Persona"<<endl;
}

Persona::~Persona(){
	//cout<<"Sto invocando il distruttore di Persona"<<endl;
}

string Persona::getCodiceFiscale() const {
	return codiceFiscale;
}

string Persona::getNome() const {
	return nome;
}

string Persona::getCognome() const {
	return cognome;
}

void Persona::setCodiceFiscale(string s){
	codiceFiscale=s;
}

void Persona::setNome(string s){
	nome=s;
}

void Persona::setCognome(string s){
	cognome=s;
}

void Persona::stampa() const {
	cout<<codiceFiscale<<" "<<nome <<" "<<cognome;
}
