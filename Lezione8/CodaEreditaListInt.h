#ifndef CODA_EREDITA_LIST_INT_H
#define CODA_EREDITA_LIST_INT_H

#include <list>
#include <iostream>
using namespace std;

class CodaEreditaListInt : protected list<int> {
	public:
		bool empty() const;
		unsigned int size() const;
		int front();
		int back();
		void push(int elem);
		void pop();
		void print() const;
};


#endif