#include"persona.h"
#include"professore.h"
#include"studente.h"
#include<list>
#include<iostream>
using namespace std;

int main() {
/*	

	questo e' senza l'ereditarieta';


	list<Professore*> professori;
	list<Studente*> studenti;

	Professore* p1 = new Professore("cf1", 1.0);
	Professore* p2 = new Professore("cf2", 2.0);
	professori.push_back(p1);
	professori.push_back(p2);

	Studente* s1 = new Studente("cf3", 1.0);
	Studente* s2 = new Studente("cf4", 1.0);
	studenti.push_back(s1);
	studenti.push_back(s2);

	for (auto p : professori)
		cout << p->getCf() << endl;

	for (auto s : studenti)
		cout << s->getCf() << endl;

	delete p1;
	delete p2;
	delete s1;
	delete s2;
	return 0;
	*/

	list<Persona*> universitari;

	Professore* p1 = new Professore("cf1", 1.0);
	Professore* p2 = new Professore("cf2", 2.0);
	Studente* s1 = new Studente("cf3", 1.0);
	Studente* s2 = new Studente("cf4", 1.0);
	universitari.push_back(p1);
	universitari.push_back(p2);
	universitari.push_back(s1);
	universitari.push_back(s2);

	for (auto p : universitari)
		cout << p->getCf() << endl;

	delete p1;
	delete p2;
	delete s1;
	delete s2;
	return 0;




}
