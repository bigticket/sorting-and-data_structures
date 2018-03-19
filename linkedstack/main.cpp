#include <iostream>

using namespace std;

/*
------------------------------ LINKED STACK -----------------------------
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
$                                                                      $
$ basic functions:                                                     $
$ push(e) - insert element e at the top of the stack                   $
$ pop() - remove the top element from the stack; an error              $
$  occurs if the stack is empty                                        $
$ top() - return a reference to the top element on the stack, without  $
$  removing it, an error occurs if the stack is empty                  $
$ size() - return the number of elements in the stack                  $
$ empty() - return true if the stack is empty and false otherwise      $
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

template <typename E>
class LinkedStack {
public:
  LinkedStack();
  int size() const;
  bool empty() const;
  const E& top() const; // value may be read, not written
  void push(const E& e);
  void pop();
private:
  SLinkedList<E> S;
  int n;
};

template <typename E>
LinkedStack<E>::LinkedStack(): S(), n(0)
{}

template <typename E>
int LinkedStack<E>::size() const
{
  return n;
}

template <typename E>
bool LinkedStack<E>::empty() const
{
  return n == 0;
}

template <typename E>
const E& LinkedStack<E>::top() const
{
  if (empty())
    cout<<"Stack is empty!"<<endl;
  else
    return S.front();
}

template <typename E>
void LinkedStack<E>::push(const E& e)
{
  ++n;
  S.addFront(e);
}

template <typename E>
void LinkedStack<E>::pop()
{
  if (empty())
    cout<<"Stack is empty!"<<endl;
  else
    --n;
    S.removeFront();
}

int main()
{
    //example
    //LinkedStack<int> S1;
    //cout<<S1.empty()<<endl;
    //S1.push(1);
    //S1.push(4);
    //cout<<S1.top()<<endl; S1.pop();
    //S1.push(9);
    //cout<<S1.top()<<endl;
    //cout<<S1.size()<<endl;
    //LinkedStack<string> S2;
    //S2.push("test");
    //cout<<S2.top()<<endl;S2.pop();
}
