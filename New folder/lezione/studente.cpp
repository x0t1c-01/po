#include"studente.h"

Studente::Studente() : Persona() {
	isee = 0.0;
}
Studente::Studente(string cf, float is) : Persona(cf) {
	isee = is;
}

float Studente::getIsee()const {
	return isee;

}
void Studente::setIsee(float is) {
	isee = is;


}