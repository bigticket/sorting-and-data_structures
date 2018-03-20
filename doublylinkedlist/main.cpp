#include <iostream>

using namespace std;

/*
------------------------------ DOUBLY LINKED LIST -----------------------------
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
$                                                                      $
$ basic functions:                                                     $
$ addFront(e) - insert element e at the front of the list              $
$ addBack(e) - insert element e at the back of the list                $
$ removeFront() - remove the element from front of the list            $
$ removeBack() - remove the element from back of the list              $
$ front() - return a reference to the element in the front of the list $
$ back() - return a reference to the element in the back of the list   $
$ empty() - return true if the list is empty and false otherwise       $
$                                                                      $
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
*/
template <typename E>
class DLinkedList;

template <typename E>
class DNode{
private:
  E elem;
  DNode<E>* prev;
  DNode<E>* next;
  friend class DLinkedList<E>;
};


template <typename E>
class DLinkedList {
public:
  DLinkedList();
  ~DLinkedList();
  bool empty() const;
  const E& front() const;
  const E& back() const;
  void addFront(const E& e);
  void addBack(const E& e);
  void removeFront();
  void removeBack();
private:
  DNode<E>* header;
  DNode<E>* trailer;
protected:
  void add(DNode<E>* v, const E& e);
  void remove(DNode<E>* v);
};

template <typename E>
DLinkedList<E>::DLinkedList()
{
  header = new DNode<E>;
  trailer = new DNode<E>;
  header->next = trailer;
  trailer->prev =  header;
}

template <typename E>
bool DLinkedList<E>::empty() const
{
  return (header->next == trailer);
}

template <typename E>
const E& DLinkedList<E>::front() const
{
  return header->next->elem;
}

template <typename E>
const E& DLinkedList<E>::back() const
{
  return trailer->prev->elem;
}

template <typename E>
DLinkedList<E>::~DLinkedList()
{
  while(!empty())
    removeFront();
  //delete header;
  //delete trailer;
}

template <typename E>
void DLinkedList<E>::add(DNode<E>* v, const E& e)
{
  DNode<E>* u = new DNode<E>; u->elem = e;
  u->next = v;
  u->prev = v->prev;
  v->prev->next = v->prev = u;
}

template <typename E>
void DLinkedList<E>::addFront(const E& e)
{
  add(header->next, e);
}

template <typename E>
void DLinkedList<E>::addBack(const E& e)
{
  add(trailer, e);
}

template <typename E>
void DLinkedList<E>::remove(DNode<E>* v)
{
  DNode<E>* u = v->prev;
  DNode<E>* w = v->next;
  u->next = w;
  w->prev = u;
  delete v;
}

template <typename E>
void DLinkedList<E>::removeFront()
{
  remove(header->next);
}

template <typename E>
void DLinkedList<E>::removeBack()
{
  remove(trailer->prev);
}

int main()
{
    //example
    //DLinkedList<string> a;
    //a.addFront("test");
    //cout<<a.front()<<endl;
    //cout<<a.empty()<<endl;
    //a.addFront("test2");
    //cout<<a.front()<<endl;
    //cout<<a.back()<<endl;
    //a.addBack("testback");
    //cout<<a.back()<<endl;
    //a.removeBack();
    //cout<<a.back()<<endl;
    //a.removeFront();
    //cout<<a.back()<<endl;
    //a.removeFront();
    //cout<<a.empty()<<endl;
    //return 0;
}
