#include <iostream>

using namespace std;

/*
------------------------------ CIRCLE LIST -----------------------------
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
$                                                                      $
$ basic functions:                                                     $
$ add(e) - insert a new node with element e immediately after the      $
$  cursor; if the list is empty, then node becomes the cursor and its  $
$  next pointer points to itself                                       $
$ remove() - remove the node immediately after the cursor(not the      $
$   cursor itself, unless it is the only node); if the list becomes    $
$   empty, the cursor is set to null                                   $
$ front() - return the element referenced by the cursor                $
$ back() - return the element immediately after the cursor             $
$ advance() - advance the cursor to the next node in the list          $
$                                                                      $
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
*/
template <typename E>
class CircleList;

template <typename E>
class CNode{
private:
  E elem;
  CNode<E> *next;
  friend class CircleList<E>;
};


template <typename E>
class CircleList {
public:
  CircleList();
  ~CircleList();
  bool empty() const;
  const E& front() const;
  const E& back() const;
  void advance();
  void add(const E& e);
  void remove();
private:
  CNode<E>* cursor;
};

template <typename E>
CircleList<E>::CircleList(): cursor(NULL)
{}

template <typename E>
bool CircleList<E>::empty() const
{
  return cursor == NULL;
}

template <typename E>
const E& CircleList<E>::front() const
{
    return cursor->next->elem;
}

template <typename E>
const E& CircleList<E>::back() const
{
    return cursor->elem;
}

template <typename E>
CircleList<E>::~CircleList()
{
  while(!empty())
    remove();
}

template <typename E>
void CircleList<E>::advance()
{
    cursor = cursor->next;
}

template <typename E>
void CircleList<E>::add(const E& e)
{
  CNode<E>* v = new CNode<E>;
  v->elem = e;
  if (cursor == NULL){
    v->next = v;
    cursor = v;
  }
  else{
    v->next = cursor->next;
    cursor->next = v;
  }
}

template <typename E>
void CircleList<E>::remove()
{
  CNode<E>* old = cursor->next;
  if (old == cursor)
    cursor = NULL;
  else
    cursor->next = old->next;
  delete old;
}

int main()
{
/*example

CircleList<string> playList;  // []
playList.add("test");         // [test*]
playList.add("test2");        // [test2, test*]
playList.add("test3");        // [test3, test2, test*]
playList.advance();           // [test2, test, test3*]
playList.advance();           // [test, test3, test2*]
playList.remove();            // [test3, test2*]
playList.add("test4");        // [test4, test3, test2*]
return 0;
*/

}
