#include<iostream>
using namespace std;

class A {
    public:
        A():c(10){};
        A(int n):c(n){}
        virtual void m() = 0;
        void stampa(){cout<<c<<endl;}
        virtual ~A(){
            cout<<"distuttore A"<<endl;
        }
    protected:
        int c;
    };

class B : public A {
    public:
        B(){d=new int(2);};
        void m(){c=c*(*d);}
        ~B(){
            delete d;
            cout<<"distuttore B"<<endl;
        }
        // + Costruttore Copia + operatore assegnamento -> regola dei 3
     private:
        int* d;
};

int main() {
    A* a = new A();
    a->m();
    (*a).stampa();  // a->stampa()
    delete a; 
    return 0;
}