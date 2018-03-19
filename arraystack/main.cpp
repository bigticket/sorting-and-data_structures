#include <iostream>

using namespace std;

/*
------------------------------ ARRAY STACK -----------------------------
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
class ArrayStack {
  enum { DEF_CAPACITY = 100};
public:
  ArrayStack(int cap = DEF_CAPACITY);
  int size() const;
  bool empty() const;
  const E& top() const; // value may be read, not written
  void push(const E& e);
  void pop();
private:
  E* S;
  int capacity;
  int t;
};

template <typename E>
ArrayStack<E>::ArrayStack(int cap)
{
  S = new E[cap];
  capacity = cap;
  t=-1; // -1 value to identify when the stack is empty
}

template <typename E>
int ArrayStack<E>::size() const
{
  return t+1;
}

template <typename E>
bool ArrayStack<E>::empty() const
{
  return t<0;
}

template <typename E>
const E& ArrayStack<E>::top() const
{
  if (empty())
    cout<<"Stack is empty!"<<endl;
  else
    return S[t];
}

template <typename E>
void ArrayStack<E>::push(const E& e)
{
  if (size()==capacity)
    cout<<"Stack is full!"<<endl;
  else
    S[++t] = e;
}

template <typename E>
void ArrayStack<E>::pop()
{
  if (empty())
    cout<<"Stack is empty!"<<endl;
  else
    --t;
}

int main()
{
    //example
    //ArrayStack<int> S1;
    //cout<<S1.empty()<<endl;
    //S1.push(1);
    //S1.push(4);
    //cout<<S1.top()<<endl; S1.pop();
    //S1.push(9);
    //cout<<S1.top()<<endl;
    //cout<<S1.size()<<endl;
    //ArrayStack<string> S2(5);
    //S2.push("test");
    //cout<<S2.top()<<endl;S2.pop();
    //S2.pop();
}
