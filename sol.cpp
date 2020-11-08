Esercizio 1.
    Soluzione 1:
        class CodaSpedizioni : private list<Spedizione*> {
            public:
                Spedizione* next() const { return front(); }
                void remove() { pop_front(); }
                unsigned int size() const { return list<Spedizione*>::size(); }
                void add(Spedizione* s) {
                    for(auto it = begin(); it != end(); ++it) {
                        if(s->getCodice() == 1) {
                            if((**it).getCodice() != 1 || s->getValore() < (**it).getValore()) {
                                insert(it, s);
                                return;
                            }
                        }
                        else if((**it).getCodice()!=1) {
                            if(s->getCodice()==2) {
                                if((**it).getCodice() != 2 || s->getPeso() < (**it).getPeso()) {
                                    insert(it, s);
                                    return;
                                }
                            }
                            else if((**it).getCodice() !=2) {
                                if(s->getId() < (**it).getId()) {
                                    insert(it, s);
                                    return;
                                }
                            }
                        }
                    }
                    push_back(s);
                }
        };
    Soluzione 2:
        bool ordina(Spedizione* s1, Spedizione* s2) {
            if(s1->getCodice()==1 && s2->getCodice()!=1)
                return true;
            if(s2->getCodice()==1 && s1->getCodice()!=1)
                return false;
            if(s1->getCodice()==1 && s2->getCodice()==1)
                return s1->getValore() < s2->getValore();

            if(s1->getCodice()==2 && s2->getCodice()!=2)
                return true;
            if(s2->getCodice()==2 && s1->getCodice()!=2)
                return false;
            if(s2->getCodice()==2 && s2->getCodice()==2)
                return s1->getPeso() < s2->getPeso();

            return s1->getId() < s2->getId();
        }

        class CodaSpedizioni : private list<Spedizione*> {
            public:
                Spedizione* next() const { return front(); }
                void remove() { pop_front(); }
                unsigned int size() const { return list<Spedizione*>::size(); }
                void add(Spedizione* s) {
                    push_back(s);
                    sort(ordina);
                }
        };

Esercizio 2.
    class Prodotto {
        public:
            virtual ~Prodotto() {}
            Prodotto(string i, float p) : id(i), prezzo(p) {}
            virtual float stampaPrezzoScontato() const { cout << prezzo << endl; }
            friend ostream& operator<<(ostream& o, const Prodotto& p) {
                p.stampa(o);
            }

            string getId() const { return id; }
            float getPrezzo() const { return prezzo; }

        protected:
            virtual ostream& stampa(ostream& o) const {
                o << "Prodotto: " << id << ", " << prezzo;
                return o;
            }

        private:
            string id,
            float prezzo;
    };

    class Libro : public Prodotto {
        public:
            Libro(string id, float prezzo, string t, string a) : Prodotto(id,prezzo), titolo(t), autore(a) {}
            float stampaPrezzoScontato() const { cout << (getPrezzo() - (getPrezzo()*0.3)) << endl; }
        protected:
            virtual ostream& stampa(ostream& o) const {
                o << "Libro: " << getId() << ", " << getPrezzo() << ", " << titolo << ", " << autore;
                return o;
            }
        private:
            string titolo;
            string autore;
    };

    class Computer : public Prodotto {
        public:
            Computer(string id, float prezzo, string m) : Prodotto(id,prezzo), modello(m) {}
            float stampaPrezzoScontato() const { cout << (getPrezzo() - (getPrezzo()*0.05)) << endl; }

        private:
            string modello;
    };

Esercizio 3.
1. L'output e' bP.
2. Linea 3, perche' la classe Test e' astratta (ha un metodo virtuale puro), quindi non puo' essere istanziata.
   Linee 4 e 5, perche' b() e bP() sono protected, quindi non visibili nel main.
   Linea 6, perche' in Test non e' definito virtual ~Test().
3. Che linee 1 e 2 del main diventerebbero scorrette.
4. Solo il distruttore e va aggiunta la keyword virtual.
