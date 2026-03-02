#include <iostream>

template < class T >
struct BiList {
    T val;
    BiList <T>* next;
    BiList <T>* prev;
};

template < class T >
void pushBack(BiList<T>* head, BiList<T>* tail, const T& value);

template < class T >
void pushFront(BiList<T>* head, BiList<T>* tail, const T& value);

template < class T >
void popBack(BiList<T>* head, BiList<T>* tail);

template < class T >
void popFront(BiList<T>* head, BiList<T>* tail);

template < class T >
void print(BiList<T>* head, BiList<T>* tail);

template < class T >
void insert(BiList<T>* head, BiList<T>* tail, const T& value, BiList<T>* buf);

template < class T >
T erase(BiList<T>* head, BiList<T>* tail, BiList<T>* buf);

int main()
{

}

template < class T >
void pushBack(BiList<T>** head, BiList<T>** tail, const T& value)
{
    BiList< T >* slot = new BiList< T >;
    slot -> val = value;
    slot -> next = nullptr;
    slot -> prev = nullptr;
    if (*head == *tail){
        *head = slot;
        *tail = slot;
    } else {
        (*tail) -> next = slot;
        slot -> prev = *tail;
        *tail = slot;
    }
}

template < class T >
void pushFront(BiList<T>** head, BiList<T>** tail, const T& value)
{
    BiList< T >* slot = new BiList< T >;
    slot -> val = value;
    slot -> next = nullptr;
    slot -> prev = nullptr;
    if (*head == *tail) {
        *head = slot;
        *tail = slot;
    } else {
        (*head) -> prev = slot;
        slot -> next = *head;
        *head = slot;
    }
}

template < class T >
T popBack(BiList<T>** head, BiList<T>** tail)
{
    if (*tail == nullptr){
        return T{};
    }
    BiList< T >* eraser = *tail;
    *tail = (*tail) -> prev;
    if (*tail == nullptr) {
        *head = nullptr;
    } else {
        (*tail) -> next = nullptr;
    }
    T k = eraser->val;
    delete eraser;
    return k;
}

template < class T >
T popFront(BiList<T>** head, BiList<T>** tail)
{
    if (*head == nullptr){
        return T{};
    }
    BiList< T >* eraser = *head;
    *head = (*head) -> next;
    if (*head == nullptr) {
        *tail = nullptr;
    } else {
        (*head) -> prev = nullptr;
    }
    T k = eraser->val;
    delete eraser;
    return k;
}
