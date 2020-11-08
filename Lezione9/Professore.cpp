#include "Professore.h"

Professore::Professore():stipendio(0){
	//cout<<"Sto invocando il costruttore di Professore"<<endl;
}

Professore::~Professore(){
	//cout<<"Sto invocando il distruttore di Professore"<<endl;
}

float Professore::getStipendio() const{
	return stipendio;
}

void Professore::setStipendio(float f){
	stipendio=f;
}

void Professore::stampa() const {
   Persona::stampa();
   cout<<stipendio;
}
