#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void stampa(const vector<int>& v){
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;	
	cout<<"Size: "<<v.size()<<endl;
	cout<<"Capacity: "<<v.capacity()<<endl;
}

int main(){
	int n;
	vector<int> v;
	cout<<"Quanti numeri vuoi inserire?"<<endl;
	cin>>n;
	cout<<"Inserisci "<<n<<" numeri"<<endl;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		v.push_back(a);
	}
	
	stampa(v);
	
	for(vector<int>::const_iterator i=v.begin();i!=v.end();i++){
		cout<<(*i)<<" ";
	}
	cout<<endl;
	
	if(v.size()>0)
		cout<<v[0]<<" "<<v.front()<<" "<<(*v.begin())<<endl;
	
	if(v.size()>0)
		cout<<v[v.size()-1]<<" "<<v.back()<<" "<<(*(v.end()-1))<<endl;
	
	if(v.size()>1)
		cout<<v[v.size()-2]<<" "<<(*(v.end()-2))<<endl;
		
	cout<<"Inserisci una dimensione minore di "<<n<<endl;
	cin>>n;
	v.resize(n,13);
	stampa(v);

	cout<<"Inserisci una dimensione maggiore di "<<n<<endl;
	cin>>n;
	v.resize(n,13);
	stampa(v);
	
	//1 2 3 3 4 -> Size 5
	sort(v.begin(),v.end());
	stampa(v);
	//1 2 3 3 4 -> Size 5
	vector<int>::iterator itUltimo=unique(v.begin(),v.end());
	stampa(v);
	//1 2 3 4 X -> Size 5
	int s=distance(v.begin(),itUltimo);
	v.resize(s);
	stampa(v);
	
	return 0;
	
}