#include "VectorInt.h"

#include <iostream>
using namespace std;

VectorInt::VectorInt() {
    sz = 0;
    cap = 1;
    vec = new int[cap];
}

VectorInt::VectorInt(const VectorInt& v) {
    sz = v.sz;
    cap = v.cap;
    vec = new int[cap];
    for(int i = 0; i < v.sz; i++) {
        vec[i] = v.vec[i];
    }
}

VectorInt::~VectorInt() {
    delete [] vec;
}

unsigned int VectorInt::size() const {
    return sz;
}

unsigned int VectorInt::capacity() const {
    return cap;
}

VectorInt& VectorInt::operator=(const VectorInt& v)
{
    if(this != &v) {
        sz = v.sz;
        cap = v.cap;
        delete [] vec;
        vec = new int[cap];
        for(int i = 0; i < v.sz; i++) {
            vec[i] = v.vec[i];
        }
    }
    return *this;
}

void VectorInt::reserve(unsigned int size) {
    if(size > cap) {
        cap = size;
        int* tmp = new int[cap];
        for(int i = 0; i < sz; i++)
            tmp[i] = vec[i];
        delete [] vec;
        vec = tmp;
    }
}

void VectorInt::resize(unsigned int size) {
    reserve(size);
    sz = size;
}

void VectorInt::push_back(int e) {
    if(sz == cap) {
        reserve(sz*2);
    }
    vec[sz] = e;
    sz++;
}

void VectorInt::pop_back() {
    if(size() > 0)
        sz--;
}

int VectorInt::operator[](unsigned int i) const {
    return vec[i];
}

int& VectorInt::operator[](unsigned int i) {
    return vec[i];
}
