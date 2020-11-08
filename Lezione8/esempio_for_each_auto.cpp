#include <iostream>
#include <list>
using namespace std;

int main(){
	list<int> l;
	for(unsigned i=0;i<10;i++)
		l.push_back(i);

	for(list<int>::const_iterator it=l.begin();it!=l.end();it++)
		cout<<(*it)<<" ";
	cout<<endl;

	for(list<int>::iterator it=l.begin();it!=l.end();it++){
		(*it)++;
		cout<<(*it)<<" ";
	}
	cout<<endl;
	
	//continuando il nostro esempio …
	float array[4]={1.2, 2.3, 3, 4};	
	for(float f: array)
		cout<<f<<" ";
	cout<<endl;

	cout<<"Iterazione con for each c++11 per valore:"<<endl;
	for(int n: l)
		cout<<n<<" ";
	cout<<endl;

	cout<<"Iterazione ed assegnamento con for each c++11 per riferimento:"<<endl;
	for(int& n: l){
		n++;
		cout<<n<<" ";
	}
	cout<<endl;
	
	//continuando il nostro esempio …
	auto stringa= "Ciao";
	auto j = 5;

	cout<<"Iterazione con for each c++11 e auto per valore:"<<endl;
	for(auto n:l)
		cout<<n<<" ";
	cout<<endl;

	cout<<"Iterazione ed assegnamento con for each c++11 e auto per riferimento:"<<endl;
	for(auto& n:l){
		n++;
		cout<<n<<" ";
	}
	cout<<endl;
	return 0;
}
