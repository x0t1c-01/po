#include <list>
#include <iostream>
using namespace std;

void stampa(const list<int>& l){
	for(list<int>::const_iterator i=l.begin();i!=l.end();i++){
		cout<<(*i)<<" ";
	}
	cout<<endl;
	cout<<"Size: "<<l.size()<<endl;	
}

int main(){
	int n;
	list<int> l;
	cout<<"Quanti numeri vuoi inserire?"<<endl;
	cin>>n;
	cout<<"Inserisci "<<n<<" numeri"<<endl;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		l.push_back(a);
	}
	
	stampa(l);
	
	if(l.size()>0)
		cout<<l.front()<<" "<<(*l.begin())<<endl;
	
	if(l.size()>0)
		cout<<l.back()<<" "<<(*(--l.end()))<<endl;
	
	if(l.size()>1){
		list<int>::const_iterator i=l.end();
		i--;
		i--;
		cout<<(*i)<<endl;
	}
	
	l.unique();
	stampa(l);
	
	l.sort();
	stampa(l);
	
	l.unique();
	stampa(l);
		
	return 0;
	
}