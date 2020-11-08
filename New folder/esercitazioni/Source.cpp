#include<iostream>
using namespace std;
double med(int a[], int n) {
	int somma = 0;
	for (int i = 0; i < n; i++) {
		somma += a[i];
	}
	double media = somma / n;
	return media;
}
bool pali(int a[], int n) {
	if (n == 0)
		return false;
	for (int i = 0; i < n; i++) {
		int x = --n;
		if (a[i] != a[x])
			return false;
	}
	return true;

}
	bool comepali(int a[], int n) {
		int cont = 0;
		int dispari = 0;
		for (int i = 0; i < n; i++) {
			cont = 0;
			for (int j = 0; j < n; j++) {
				if (a[i] == a[j])
					cont++;
			}
			if (n % 2 == 0 and cont % 2 != 0)
				return false;
			else if(n % 2 != 0 and cont % 2 != 0) {
				if (dispari == 0)
					dispari = a[i];
				else if (dispari != a[i])
					return false;
			}
		}
		return true;
	}

	int sommamin(int a[], int n) {
		somma min = INT_MAX;
		int c, b, d;
		for (int i = 0; i < n; i++) {
			if (i != 0 || i != n - 1) {
				if (a[i - 1] + a[i] + a[i + 1] < min) {
					min = a[i - 1] + a[i] + a[i + 1];
					c = a[i - 1];
					b = a[i];
					d = a[i + 1];
				}
					
			}
		}
		cout << c << ' ' << b << ' ' << d;
	}

	
	int main() {
	int a[100];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << med(a, n);

}