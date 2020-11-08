#include "CodaEreditaListInt.h"

bool CodaEreditaListInt::empty() const {
	return list<int>::empty(); 
}

unsigned int  CodaEreditaListInt::size() const {
	return list<int>::size(); 
}

int  CodaEreditaListInt::front() {
	return list<int>::front();
}

int  CodaEreditaListInt::back() {
	return list<int>::back(); 
}

void CodaEreditaListInt::push(int elem){
	push_back(elem);
}

void CodaEreditaListInt::pop(){
	if(!empty()) 
		pop_front();
}

void CodaEreditaListInt::print() const {
	for(list<int>::const_iterator it=begin();it!=end();it++)
		cout<<*it<<" ";
	cout<<endl;
}