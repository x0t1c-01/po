#include "Prodotto.h"
#include <iostream>
using namespace std;

int main() {
  Prodotto p1;
  p1.setId(1);
  p1.setPrezzo(3.5);

  cout << "Prodotto " << p1.getId() << " " << p1.getPrezzo() << endl;
  return 0;
}
