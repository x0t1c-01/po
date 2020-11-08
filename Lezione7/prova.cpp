#include <iostream>
using namespace std;

class A {
	private:
		int n_private;
	protected:
		int n_protected;
	public:
		int n_public;
		A(): n_private(0),n_protected(1),n_public(2){};
};

class B : public A {
	public:
		void stampa(){
			//cout<<"n_private: "<<n_private<<endl; //NON SI PUO'
			cout<<"n_protected: "<<n_protected<<endl;
			cout<<"n_public: "<<n_public<<endl;
		}
};


int main(){
	B oggettoB;
	oggettoB.stampa();
	cout<<oggettoB.n_public<<endl;
	return 0;
}