#ifndef PRODOTTO_H
#define PRODOTTO_H

class Prodotto {
  public:
    Prodotto();
    int getId() const;
    void setId(int);
    float getPrezzo() const;
    void setPrezzo(float);

  private:
    int id;
    float prezzo;
};

#endif
