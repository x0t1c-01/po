#include <iostream>
#include "GestoreContatti.h"
using namespace std;

int main(){
	GestoreContatti g;
	int n=0;
	cout<<"Quanti contatti vuoi inserire?"<<endl;
	cin>>n;
	for(int i=0;i<n;i++){
		Contatto c;
		cin>>c;
		g.inserisciContatto(c);
	}
	cout<<"Contatti inseriti:"<<endl;
	g.stampaContatti();
	g.ordina();
	cout<<"Contatti dopo ordinamento "<<endl;
	g.stampaContatti();
	cout<<"Cognome piu' frequente: "<<g.cognomePiuFrequente()<<endl;
	if(g.verificaDueContattiStessoTelefono())
		cout<<"Ci sono due contatti con stesso telefono"<<endl;
	else
		cout<<"Non ci sono due contatti con stesso telefono"<<endl;
	vector<string> num=g.trovaNumeri("mario","rossi");
	if(num.empty())
		cout<<"mario rossi non e' presente"<<endl;
	else{
		cout<<"i numeri di mario rossi sono"<<endl;
		for(int i=0;i<num.size();i++)
			cout<<num[i]<<endl;
	}
	Contatto c("luca","bianchi","123","luca@gmail.com");
	g.inserisciContatto(c);
	g.stampaContatti();
	g.eliminaContattoConRemove(c);
	g.stampaContatti();
	cout<<"------------------------"<<endl;
	
	g.inserisciContatto(c);
	g.stampaContatti();
	g.eliminaContattoConErase(c);
	g.stampaContatti();
	
	return 0;
}
