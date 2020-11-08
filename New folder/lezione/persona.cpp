#include"persona.h"

Persona::Persona() {
	cf = "";
}
Persona::Persona(string cf) {
	this->cf = cf;
}
void Persona::setCf(string c) {
	cf = c;
}
string Persona::getCf()const {
	return cf;
}
