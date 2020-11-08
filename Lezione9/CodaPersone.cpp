#include "CodaPersone.h"

bool CodaPersone::empty() const {
	return list<Persona*>::empty(); 
}

unsigned int  CodaPersone::size() const {
	return list<Persona*>::size(); 
}

Persona*  CodaPersone::front() {
	return list<Persona*>::front();
}

Persona*  CodaPersone::back() {
	return list<Persona*>::back(); 
}

void CodaPersone::push(Persona* elem){
	push_back(elem);
}

void CodaPersone::pop(){
	if(!empty()) 
		pop_front();
}

void CodaPersone::print() const {
	for(auto p:*this){
		p->stampa();
		cout<<endl;
	}
	/*for(list<Persona*>::const_iterator it=begin();it!=end();it++){
		(*(*it)).stampa();
		cout<<endl;
	}*/
}


