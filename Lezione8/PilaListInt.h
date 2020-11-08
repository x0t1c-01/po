#ifndef PILA_LIST_INT_H
#define PILA_LIST_INT_H

#include <list>
#include <iostream>
using namespace std;

class PilaListInt {
    public:
        bool empty() const;
        unsigned int size() const;
        int front();
        int back();
        void push(int elem);
        void pop();
		void print() const;

    private:
        list<int> elements;
		
};

#endif