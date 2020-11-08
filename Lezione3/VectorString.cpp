#include "VectorString.h"

VectorString::VectorString() {
    sz = 0;
    cap = 1;
    vec = new string[cap];
}


VectorString::VectorString(const VectorString& v) {
    sz = v.sz;
    cap = v.cap;
    vec = new string[cap];
    for(int i = 0; i < v.sz; i++) {
        vec[i] = v.vec[i];
    }
}

VectorString& VectorString::operator=(const VectorString& v)
{
    if(this != &v) {
        sz = v.sz;
        cap = v.cap;
        delete [] vec;
        vec = new string[cap];
        for(int i = 0; i < sz; i++) {
            vec[i] = v.vec[i];
        }
    }
    return *this;
}


VectorString::~VectorString() {
    delete [] vec;
}


unsigned int VectorString::size() const {
    return sz;
}


unsigned int VectorString::capacity() const {
    return cap;
}

void VectorString::push_back(const string& e) {
    if(sz == cap) {
		cap = cap*2;
        string* tmp = new string[cap];
        for(int i = 0; i < sz; i++)
            tmp[i] = vec[i];
        delete [] vec;
        vec = tmp;
    }
    vec[sz] = e;
    sz++;
}


void VectorString::pop_back() {
    if(sz > 0)
        sz--;
}

bool VectorString::operator==(const VectorString& v){
	if(sz!=v.sz) return false;
	
	for(int i = 0; i < sz; i++) {
		bool found=false;
		for(int j = 0; j < v.sz && !found; j++) {
			if(vec[i]==v.vec[i])
				found=true;
		}
		if(!found) return false;
	}
	return true;
}

string VectorString::operator[](unsigned int i) const {
    return vec[i];
}


string& VectorString::operator[](unsigned int i) {
    return vec[i];
}