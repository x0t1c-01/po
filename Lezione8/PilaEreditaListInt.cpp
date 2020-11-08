#include "PilaEreditaListInt.h"

bool PilaEreditaListInt::empty() const {
	return list<int>::empty();
}

unsigned int PilaEreditaListInt::size() const {
	return list<int>::size();
}

int PilaEreditaListInt::front() {
	return list<int>::front();
}

int PilaEreditaListInt::back() {
	return list<int>::back();
}

void PilaEreditaListInt::push(int elem){
	push_back(elem);
}

void PilaEreditaListInt::pop(){
	if(!empty())
		pop_back();
}

void PilaEreditaListInt::print() const {
	for(list<int>::const_iterator it=begin();it!=end();it++)
		cout<<*it<<" ";
	cout<<endl;
}