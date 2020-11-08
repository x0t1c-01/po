#ifndef Vector_H_
#define Vector_H_

#include <iostream>
using namespace std;

template<class R>
class Vector
{
    public:
        Vector();
        Vector(const Vector<R>&);
        ~Vector();

        unsigned int size() const;
        unsigned int capacity() const;

        void push_back(R e);
        void pop_back();
        void reserve(unsigned int size);
        void resize(unsigned int size);

        R operator[](unsigned int i) const;
        R& operator[](unsigned int i);

        Vector& operator=(const Vector<R>& v);

    private:
        R* vec;
        unsigned int sz;
        unsigned int cap;
};

template<class R>
Vector<R>::Vector() {
    sz = 0;
    cap = 1;
    vec = new R[cap];
}

template<class R>
Vector<R>::Vector(const Vector<R>& v) {
    sz = v.sz;
    cap = v.cap;
    vec = new R[cap];
    for(int i = 0; i < v.sz; i++) {
        vec[i] = v.vec[i];
    }
}

template<class R>
Vector<R>::~Vector() {
    delete [] vec;
}

template<class R>
unsigned int Vector<R>::size() const {
    return sz;
}

template<class R>
unsigned int Vector<R>::capacity() const {
    return cap;
}

template<class R>
Vector<R>& Vector<R>::operator=(const Vector<R>& v)
{
    if(this != &v) {
        sz = v.sz;
        cap = v.cap;
        delete [] vec;
        vec = new R[cap];
        for(int i = 0; i < v.sz; i++) {
            vec[i] = v.vec[i];
        }
    }
    return *this;
}

template<class R>
void Vector<R>::reserve(unsigned int size) {
    if(size > cap) {
        cap = size;
        R* tmp = new R[cap];
        for(int i = 0; i < sz; i++)
            tmp[i] = vec[i];
        delete [] vec;
        vec = tmp;
    }
}

template<class R>
void Vector<R>::resize(unsigned int size) {
    reserve(size);
    sz = size;
}

template<class R>
void Vector<R>::push_back(R e) {
    if(sz == cap) {
        reserve(sz*2);
    }
    vec[sz] = e;
    sz++;
}

template<class R>
void Vector<R>::pop_back() {
    if(size() > 0)
        sz--;
}

template<class R>
R Vector<R>::operator[](unsigned int i) const {
    return vec[i];
}

template<class R>
R& Vector<R>::operator[](unsigned int i) {
    return vec[i];
}

#endif
