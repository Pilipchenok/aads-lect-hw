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
