#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include "Automobile.h"
using namespace std;


int main(){

//ese 1
    int n;
    cin>>n;
    string t,m;
    int anno;
    double p;
    Automobile* a = new Automobile[n];
        for(int i=0;i<n;i++){
            cin >> t;
            cin >> p;
            cin >> m;
            cin >> anno;
            a[i].setTarga(t);
            a[i].setPrezzo(p);
            a[i].setMarca(m);
            a[i].setAnnoprod(anno);
        }

//ese 2
    double maxpre=INT_MIN;
    for(int i=0;i<n;i++){
        if(a[i].getPrezzo()>maxpre)
            maxpre=a[i].getPrezzo();
    }
        cout<<maxpre<<endl;
        
//ese 3
    vector<string> marche;
    for(int i=0;i<n;i++){
        if(find(marche.begin(),marche.end(),a[i].getMarca())==marche.end())
            marche.push_back(a[i].getMarca());
    }
    int count = 0;
    int count2 = 0;
    for(int i = 0; i < marche.size(); i++) {
        int contaLusso = 0;
        int contaAuto = 0;
        for(int j = 0; j < n; j++)
            if(a[j].getMarca() == marche[i]) {
                contaAuto++;
                if(a[j].getPrezzo() >= 100000)
                    contaLusso++;
            }
        if(contaAuto == contaLusso)
            count++;
        if(contaLusso==0)
            count2++;
    }

    cout << count << endl;

//ese 4
    cout<< count2 << endl;

//ese 5
    for(int i = 0; i < marche.size(); i++) {
        bool trovato = false;
        for(int j = 0; j < n; j++)
            if(a[j].getMarca() == marche[i]) {
                if(a[j].getAnnoprod() == 2015 and a[j].getPrezzo() > 10000)
                    trovato = true;
            }
        if(trovato)
            cout << marche[i] << endl;
    }

//ese 6
    vector<int> anni;
    for(int i=0;i<n;i++){
        if(find(anni.begin(),anni.end(),a[i].getAnnoprod())==anni.end())
            anni.push_back(a[i].getAnnoprod());
    }

    int max = INT_MIN;
    int annoMax = 0;
    for(int i = 0; i < anni.size(); i++) {
        int autoProdotte = 0;
        for(int j = 0; j <  n; j++) {
            if(a[j].getAnnoprod() == anni[i])
                autoProdotte++;
        }
        if(autoProdotte > max) {
            max = autoProdotte;
            annoMax = anni[i];
        }
    }
    cout << annoMax << endl;


    delete [] a;
    return 0;
}
