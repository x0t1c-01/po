#include<iostream>
#include "VectorInt.h"
#include<c.math>
#include<climits>
using namespace std;

void aggiungiElementi(VectorInt& v){
	int elemento=rand();
	v.push_back(elemento);
}

void rimuoviElementi(VectorInt& v, int n){
	if(n>size){
		for(int i=0;i<v.size();i++)
			v.pop_back();
	}
	for(int i=v.size();i>n;i--){
		v.pop_back();
	}
	
}

void scambiaVettori(VectorInt& v1, VectorInt& v2){
	VectorInt v3;
	v3=v1;
	v1=v2;
	v2=v3;
}

int massimo(VectorInt& v){
	int max=INT_MAX;
	for(int i=0;i<v.size();i++){
		if(v[i]>max)
			max=v[i];
	}
	
	return max;
}

int minimo(VectorInt& v){
	int min=INT_MIN;
	for(int i=0;i<v.size();i++){
		if(v[i]<min)
			min=v[i];
	}
	
	return min;
}

VectorInt sommaVettori(VectorInt& v1, VectorInt& v2){
	VectorInt vs[v1.size()];
	for(int i=0;i<v1.size;i++){
		vs[i]=v1[i]+v2[i];
	}
	return vs;
}

int prodottoScalare(VectorInt& v1, VectorInt& v2){
	VectorInt vs[v1.size()];
	for(int i=0;i<v1.size;i++){
		vs[i]=v1[i]*v2[i];
	}
	return vs;
}

bool opposto(VectorInt& v1, VectorInt& v2){
	bool s=false;
	
	for(int i=0;i<v1.size();i++){
		s=false;
		for(int j=0;j<v1.size();j++){
			if(v1[i]+v2[j]==0);
				s=true;
			
		}
		if(!s)
			return false;
	}
	return true;
}

int sottosequenza(VectorInt& v){
	int cont=0;
	int maxseq=0;
	for(int i=0;i<v.size();i++){
		if(v[i]%2==0)
			cont++;
		else
			if(cont>maxseq)
				maxseq=cont;
			cont=0;
	}
	return maxseq;
}

int frequente(VectorInt& v){
	int cont=0;
	int nummax=0;
	int max=0;
	for(int i=0;i<v.size();i++)
		for(int j=0;i<=v.size();i++){
			if(v[i]==v[j])
				cont++;
		}
		if(cont>max)
			max=cont;
			cont=0;	
			nummax=v[i];
	}
	return nummax;
}

int main(){
	VectorInt v;
	aggiungiElementi(v);
	rimuoviElementi(v,n);
	
	
	return 0;
}
