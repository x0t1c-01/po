#include "CodaListInt.h"

bool CodaListInt::empty() const {
	return elements.empty();
}

unsigned int CodaListInt::size() const {
	return elements.size();
}

int CodaListInt::front() {
	return elements.front();
}

int CodaListInt::back() {
	return elements.back();
}

void CodaListInt::push(int elem){
	elements.push_back(elem);
}

void CodaListInt::pop(){
	if(!empty())
		elements.pop_front();
}

void CodaListInt::print() const {
	for(list<int>::const_iterator it=elements.begin();it!=elements.end();it++)
		cout<<*it<<" ";
	cout<<endl;
}