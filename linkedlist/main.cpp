#include <iostream>

using namespace std;

/*
------------------------------ LINKED LIST -----------------------------
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
$                                                                      $
$ basic functions:                                                     $
$ addFront(e) - insert element e at the front of the list              $
$ removeFront() - remove the element from front of the list            $
$ front() - return a reference to the element in the front of the list $
$ empty() - return true if the list 11 is empty and false otherwise    $
$                                                                      $
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
*/
template <typename E>
class SLinkedList;

template <typename E>
class SNode{
private:
  E elem;
  SNode<E> *next;
  friend class SLinkedList<E>;
};


template <typename E>
class SLinkedList {
public:
  SLinkedList();
  ~SLinkedList();
  bool empty() const;
  const E& front() const;
  void addFront(const E& e);
  void removeFront();
private:
  SNode<E>* head;
};

template <typename E>
SLinkedList<E>::SLinkedList()
{
  head=NULL;
}

template <typename E>
bool SLinkedList<E>::empty() const
{
  return head == NULL;
}

template <typename E>
const E& SLinkedList<E>::front() const
{
    return head->elem;
}

template <typename E>
SLinkedList<E>::~SLinkedList()
{
  while(!empty())
    removeFront();
}

template <typename E>
void SLinkedList<E>::addFront(const E& e)
{
  SNode<E> *v = new SNode<E>;
  v->elem = e;
  v->next = head;
  head = v;
}

template <typename E>
void SLinkedList<E>::removeFront()
{
  SNode<E> *old = head;
  head = old->next;
  delete old;
}

int main()
{
    //example
    //SLinkedList<string> a;
    //a.addFront("test");
    //cout<<a.front()<<endl;
    //cout<<a.empty()<<endl;
    //a.addFront("test2");
    //cout<<a.front()<<endl;
    //a.~SLinkedList();
    //cout<<a.empty()<<endl;
    //return 0;
}
