#include "Studente.h"

Studente::Studente():Persona(),isee(0){
	//nome="studente";
	//setNome("studente");
	//cout<<"Sto invocando il costruttore di Studente"<<endl;
}

Studente::~Studente(){
	//cout<<"Sto invocando il distruttore di Studente"<<endl;
}

float Studente::getIsee() const{
	return isee;
}

void Studente::setIsee(float f){
	isee=f;
}

void Studente::stampa() const {
   Persona::stampa();
   cout<<isee;
}