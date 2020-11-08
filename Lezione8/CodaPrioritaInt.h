#ifndef CODA_PRIORITA_INT_H
#define CODA_PRIORITA_INT_H

#include "CodaEreditaListInt.h"
#include <iostream>
using namespace std;

class CodaPrioritaInt : public CodaEreditaListInt {
	public:
		void push(int n) {
			list<int>::iterator it = begin();
			while ( it != this->end() && n <= (*it) )
				it++;
			insert(it,n); // metodo di list STL
		}	
};

#endif