#include<iostream>
#include<vector>
using namespace std;

void leggi(vector<int>& v){
    int x;
    cin>>x;
    while(x!=-1){
        v.push_back(x);
        cin>>x;
    }
}

void stampa(vector<int>& v,int size){
    if(size>v.size())
        return;

    for(int i=0;i<size;i++){
            cout<<v[i]<<' ';
    }
    cout<<endl;
}


void ordina(vector <int>& v){
    bool cambio=true;
        while(cambio){
            cambio=false;
            for(int i=0;i<v.size()-1;i++){
                if((v[i]%2==0 && v[i+1]%2!=0)||(v[i]%2 == v[i+1]%2) && v[i]>v[i+1]){
                    int tmp=v[i];
                    v[i]=v[i+1];
                    v[i+1]=tmp;
                    cambio=true;
                }
            }
        }
}

int main(){

    vector<int> v;
    leggi(v);
    stampa(v,v.size());
    int n;
    cin>>n;
    stampa(v,n);
    ordina(v);
    stampa(v,v.size());
    v.clear();


    return 0;
}
