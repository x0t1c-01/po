#include "PilaListInt.h"

bool PilaListInt::empty() const {
	return elements.empty();
}

unsigned int PilaListInt::size() const {
	return elements.size();
}

int PilaListInt::front() {
	return elements.front();
}

int PilaListInt::back() {
	return elements.back();
}

void PilaListInt::push(int elem){
	elements.push_back(elem);
}

void PilaListInt::pop(){
	if(!empty())
		elements.pop_back();
}

void PilaListInt::print() const {
	for(list<int>::const_iterator it=elements.begin();it!=elements.end();it++)
		cout<<*it<<" ";
	cout<<endl;
}