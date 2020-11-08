#ifndef CODA_PRIORITA_INT_VERSIONE_2_H
#define CODA_PRIORITA_INT_VERSIONE_2_H

#include <list>
#include <iostream>
using namespace std;

class CodaPrioritaIntVersione2 : protected list<int> {
	public:
		bool empty() const {
			return list<int>::empty();
		}
		
		unsigned int size() const { 
			return list<int>::size(); 
		}
		
		int front() { 
			return list<int>::front(); 
		}
		
		int back() {
			return list<int>::back();
		}
		
		void pop() {
			if(!empty())
				pop_front();
		}
		
		void print() const { 
			for(list<int>::const_iterator it=begin();it!=end();it++)
				cout<<*it<<" ";
			cout<<endl;
		}
		
		void push(int n) {
			list<int>::iterator it = begin();
			while ( it != this->end() && n <= (*it) )
				it++;
			insert(it,n);
		}
};

#endif
