#ifndef LIST_H
#define LIST_H

template <class T>
class List {

    private:
        struct Node {
            Node* previous;
            Node* next;
            T value;
        };
        
        Node* head;
        Node* tail;
    public:
        List();
        void push_back(T value);
        void pop_back();
        void push_front(T value);
        void pop_front();
        bool empty() const;
        void clear();
        ~List();
        List(const List<T>& l);
        List<T>& operator=(const List<T>& l);
        
        class Iterator {
            friend class List<T>;
            private:
                Node* current;
                Iterator(Node* n) {
                    current = n;
                }
                
            public:                

                Iterator& operator++() {
                    current = current->next;
                    return *this;
                }
                
                Iterator operator++(int) {
                    Iterator tmp(current);
                    current = current->next;
                    return tmp;
                }
                
                T& operator*() const {
                    return current->value;
                }
                
                bool operator==(Iterator i) const {
                    return current == i.current;
                }
                
                bool operator!=(Iterator i) const {
                    return current != i.current;                    
                }
        };                  
        
        Iterator begin() { return Iterator(head); }
        Iterator end() { return Iterator(nullptr); }
};

template <class T>
List<T>::List() {
    head = nullptr;
    tail = nullptr;
}

template <class T>
void List<T>::push_back(T value) {
    Node* node = new Node();
    node->previous = tail;
    node->next = nullptr;
    node->value = value;
    if(tail != nullptr) {
        tail->next = node;
        tail = node;
    }
    else {
        head = node;
        tail = node;    
    }
}

template <class T>
void List<T>::push_front(T value) {
    Node* node = new Node();
    node->previous = nullptr;
    node->next = head;
    node->value = value;
    if(head != nullptr) {
        head->previous = node;
        head = node;
    }
    else {
        head = node;
        tail = node;    
    }
}

template <class T>
void List<T>::pop_back() {
    if(head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;
    }
    else {
        Node* p = tail->previous;
        p->next = nullptr;
        delete tail;
        tail = p;
    }
}

template <class T>
void List<T>::pop_front() {
    if(head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;
    }
    else {
        Node* n = head->next;
        n->previous = nullptr;
        delete head;
        head = n;
    }
}

template <class T>
bool List<T>::empty() const {
    return head == nullptr;
}

template <class T>
void List<T>::clear() {
    while(!empty())
        pop_back();
}

template <class T>
List<T>::~List() {
    clear();
}

template <class T>
List<T>::List(const List<T>& l) {
    Node* current = l.head;
    while(current != nullptr) {
        push_back(current->value);
        current = current->next;
    }
}

template <class T>
List<T>& List<T>::operator=(const List<T>& l) {
    if(this != &l) {
        clear();
        Node* current = l.head;
        while(current != nullptr) {
            push_back(current->value);
            current = current->next;
        }
    }
    return *this;
}

#endif