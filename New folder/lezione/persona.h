#ifndef PERSONA_H
#define PERSONA_H

#include<string>
using namespace std;

class Persona {

public:
	Persona();
	Persona(string cf);
	void setCf(string cf);
	string getCf()const;


private:
	string cf;
};

#endif
