#include <iostream>

template <class T> struct BiList
{
  T val;
  BiList<T> *next;
  BiList<T> *prev;
};

template <class T>
void pushBack(BiList<T> **head, BiList<T> **tail, const T value);

template <class T>
void pushFront(BiList<T> **head, BiList<T> **tail, const T value);

template <class T> T popBack(BiList<T> **head, BiList<T> **tail);

template <class T> T popFront(BiList<T> **head, BiList<T> **tail);

template <class T> void print(BiList<T> *head, BiList<T> *tail);

template <class T>
void insert(BiList<T> **head, BiList<T> **tail, const T value, BiList<T> *buf);

template <class T> T erase(BiList<T> **head, BiList<T> **tail, BiList<T> *buf);

template <class T> void clear(BiList<T> **head, BiList<T> **tail);

int main()
{
  size_t n = 10;
  int *a = new int[n];
  for (size_t i = 0; i < n; ++i)
  {
    a[i] = i;
  }
  BiList<int> *head = nullptr;
  BiList<int> *tail = nullptr;
  try
  {
    for (size_t i = 0; i < n; ++i)
    {
      pushBack(&head, &tail, a[i]);
    }
  } catch (...)
  {
    clear(&head, &tail);
    delete[] a;
    return 1;
  }
  print(head, tail);
  delete[] a;
  clear(&head, &tail);
}

template <class T>
void pushBack(BiList<T> **head, BiList<T> **tail, const T value)
{
  BiList<T> *slot = new BiList<T>; //T::T()
  slot->val = value; //T::operator=(const T)
  slot->next = nullptr;
  slot->prev = nullptr;
  if (*head == nullptr)
  {
    *head = slot;
    *tail = slot;
  }
  else
  {
    (*tail)->next = slot;
    slot->prev = *tail;
    *tail = slot;
  }
}

template <class T>
void pushFront(BiList<T> **head, BiList<T> **tail, const T value)
{
  BiList<T> *slot = new BiList<T>; //T::T()
  slot->val = value; //T::operator=(const T)
  slot->next = nullptr;
  slot->prev = nullptr;
  if (*head == nullptr)
  {
    *head = slot;
    *tail = slot;
  }
  else
  {
    (*head)->prev = slot;
    slot->next = *head;
    *head = slot;
  }
}

template <class T> T popBack(BiList<T> **head, BiList<T> **tail)
{
  if (*tail == nullptr)
  {
    return T{}; // T::T()
  }
  BiList<T> *eraser = *tail;
  *tail = (*tail)->prev;
  if (*tail == nullptr)
  {
    *head = nullptr;
  }
  else
  {
    (*tail)->next = nullptr;
  }
  T k = eraser->val; //T::T(const T&)
  delete eraser;
  return k;
}

template <class T> T popFront(BiList<T> **head, BiList<T> **tail)
{
  if (*head == nullptr)
  {
    return T{}; // T::T()
  }
  BiList<T> *eraser = *head;
  *head = (*head)->next;
  if (*head == nullptr)
  {
    *tail = nullptr;
  }
  else
  {
    (*head)->prev = nullptr;
  }
  T k = eraser->val; //T::T(const T&)
  delete eraser;
  return k;
}

template <class T> void print(BiList<T> *head, BiList<T> *tail)
{
  if (head != nullptr)
  {
    while (head != tail)
    {
      std::cout << head->val << " ";
      head = head->next;
    }
    std::cout << head->val << "\n";
  }
}

template <class T>
void insert(BiList<T> **head, BiList<T> **tail, const T value, BiList<T> *pos)
{
  if (pos == nullptr)
  {
    return;
  }
  BiList<T> *slot = new BiList<T>; //T::T()
  slot->val = value; //T::operator=(const T)
  slot->next = nullptr;
  slot->prev = nullptr;
  if (*head == nullptr)
  {
    *head = slot;
    *tail = slot;
  }
  else
  {
    BiList<T> *buf = *head;
    while (buf != pos && buf != *tail)
    {
      buf = buf->next;
    }
    buf = pos->next;

    pos->next = slot;
    slot->prev = pos;
    slot->next = buf;

    if (buf != nullptr)
    {
      buf->prev = slot;
    }
    else
    {
      *tail = slot;
    }
  }
}

template <class T> T erase(BiList<T> **head, BiList<T> **tail, BiList<T> *pos)
{
  if (*head == nullptr)
  {
    return {};
  }
  if (*head == *tail)
  {
    if (*head != pos)
    {
      return T{}; // T::T()
    }
    T res = (*head)->val; //T::T(const T&)
    *tail = nullptr;
    delete *head;
    *head = nullptr;
    return res;
  }
  else
  {
    BiList<T> *buf = *head;
    while (buf != pos && buf != *tail)
    {
      buf = buf->next;
    }
    if (buf != pos)
    {
      return T{}; // T::T()
    }
    BiList<T> *preBuf = buf->prev;
    BiList<T> *aftBuf = buf->next;
    if (aftBuf == nullptr)
    {
      preBuf->next = nullptr;
      *tail = preBuf;
    }
    else if (preBuf == nullptr)
    {
      aftBuf->prev = nullptr;
      *head = aftBuf;
    }
    else
    {
      preBuf->next = aftBuf;
      aftBuf->prev = preBuf;
    }

    T res = buf->val; //T::T(const T&)
    delete buf;
    return res;
  }
}

template <class T> void clear(BiList<T> **head, BiList<T> **tail)
{
  while (*head != nullptr)
  {
    popBack(head, tail);
  }
}
