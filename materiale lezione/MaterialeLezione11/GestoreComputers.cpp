/*
Data la seguente definizione:
Un computer C1 e' connesso con un Computer C2 se:
- C1 e' connesso con C2, oppure
- C1 e' connesso con C3 e C3 e' connesso con C2.

Il metodo deve restituire il numero massimo di computer connessi tra loro.

Nel caso in cui non ci siano computers restituisce -1.
            
*/
int connessi(string n, const list<Computer>& computers) {
    vector<string> conn;
    for(auto c : computers)
        if(c.getNomeComputer() == n)
            if(find(conn.begin(), conn.end(), c.getConnessoA()) == conn.end())
                conn.push_back(c.getConnessoA());            
    for(int i = 0; i < conn.size(); i++)
        for(auto c : computers)
            if(c.getNomeComputer() == conn[i])
                if(find(conn.begin(), conn.end(), c.getConnessoA()) == conn.end())
                    conn.push_back(c.getConnessoA());
    
    return conn.size();
}

int GestoreComputers::metodo4()
{
    if(computers.empty())
        return -1;
    int max = INT_MIN;
    for(auto c : computers) {
        int conn = connessi(c.getNomeComputer(), computers);
        if(conn > max)
            max = conn;
    }
    return max;
}


/*

SECONDA VARIANTE

Data la seguente definizione:
Un computer C1 e' connesso con un Computer C2 se:
- C1 e' connesso con C2, oppure
- C1 e' connesso con C3 e C3 e' connesso con C2.

Il metodo deve restituire il numero massimo di computer connessi tra loro.

ATTENZIONE: Un computer e' sempre connesso con se stesso.

Nel caso in cui non ci siano computers restituisce -1.
            
*/
int connessi(string n, const list<Computer>& computers) {
    vector<string> conn;
    conn.push_back(n);
    for(int i = 0; i < conn.size(); i++)
        for(auto c : computers)
            if(c.getNomeComputer() == conn[i])
                if(find(conn.begin(), conn.end(), c.getConnessoA()) == conn.end())
                    conn.push_back(c.getConnessoA());
    
    return conn.size();
}

int GestoreComputers::metodo4()
{
    if(computers.empty())
        return -1;
    int max = INT_MIN;
    for(auto c : computers) {
        int conn = connessi(c.getNomeComputer(), computers);
        if(conn > max)
            max = conn;
    }
    return max;
}