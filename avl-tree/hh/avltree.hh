#ifndef AVLTREE_HH
#define AVLTREE_HH

#include "avlnode.hh"

using namespace std;

/*
------------------------------ AVL - TREE ------------------------------
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
$                                                                      $
$ class AVLTree represents the special type of binary tree             $
$                                                                      $
$ root        - means root of the tree                                 $
$ add_elem    - inserts new node in the AVLTree                        $
$ remove_elem - remove wanted node from the AVLTree                    $
$ show_root   - prints info about root of the AVLTree                  $                                                                     $
$ show_height - prints the height of the AVLTree                       $
$ preorder    - prints info about nodes using preorder tree traversal  $
$ inorder     - prints info about nodes using inorder tree traversal   $
$ postorder   - prints info about nodes using postorder tree traversal $
$                                                                      $
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
*/

template <typename E>
class AVLTree{
public:
  AVLTree();                                        // constructor
  ~AVLTree();                                       // destructor
  void add_elem(E elem);
  void remove_elem(E elem);
  void show_root();
  void show_height();
  void preorder();
  void inorder();
  void postorder();
private:
  AVLNode<E>* root;
  bool empty();
  void RR(AVLNode<E>* &root, AVLNode<E>* temp); // left-left rotation
  void LL(AVLNode<E>* &root, AVLNode<E>* temp); // right-right rotation
  void RL(AVLNode<E>* &root, AVLNode<E>* temp); // left-right rotation
  void LR(AVLNode<E>* &root, AVLNode<E>* temp); // right-left rotation
  void rebalance(AVLNode<E>* temp);             // rebalances AVL-Tree        
  void add(E elem, AVLNode<E>* temp);           // inserts new node
  void remove(AVLNode<E>* temp);                // removes wanted node
  void pre_order(AVLNode<E>* temp);             // preorder traversal
  void in_order(AVLNode<E>* temp);              // inorder traversal
  void post_order(AVLNode<E>* temp);            // postorder traversal
  int height(AVLNode<E>* temp);                 // returns node's height
  void check_bf(AVLNode<E>* temp);              // checks node's bf
  int maxKey(AVLNode<E>* temp);                 // returns max key
  int minKey(AVLNode<E>* temp);                 // returns min key
  AVLNode<E>* maxNode(AVLNode<E>* temp);    // returns node with max key
  AVLNode<E>* minNode(AVLNode<E>* temp);    // returns node with min key
  AVLNode<E>* pred(AVLNode<E>* temp);      // returns predecessor's node
  AVLNode<E>* search(E elem, AVLNode<E>* temp); // finds wanted node
};

template <typename E>
AVLTree<E>::AVLTree()
{
  root = NULL;
}

template <typename E>
AVLTree<E>::~AVLTree()
{
  delete root;
}

template <typename E>
bool AVLTree<E>::empty()
{
  if(root) return false;
  else return true;
}

template <typename E>
void AVLTree<E>::RR(AVLNode<E>* &root, AVLNode<E>* temp)
{
  cout << "ROTATION RR" << endl;
  AVLNode<E>* r = temp->get_right();
  AVLNode<E>* p = temp->get_up();
  temp->set_right(r->get_left());

  if(temp->get_right()) temp->get_right()->set_up(temp);

  r->set_left(temp);
  temp->set_up(r);
  r->set_up(p);

  if(p)
  {
    if(p->get_left() == temp) p->set_left(r);
    else p->set_right(r);
  }
  else root = r;

  if(r->get_bf() == -1)
  {
      temp->set_bf(0);
      r->set_bf(0);
  }
  else
  {
      temp->set_bf(-1);
      r->set_bf(1);
  }
}

template <typename E>
void AVLTree<E>::LL(AVLNode<E>* &root, AVLNode<E>* temp)
{
  cout << "ROTATION LL" << endl;
  AVLNode<E>* l = temp->get_left();
  AVLNode<E>* p = temp->get_up();
  temp->set_left(l->get_right());

  if(temp->get_left()) temp->get_left()->set_up(temp);

  l->set_right(temp);
  l->set_up(p);
  temp->set_up(l);

  if(p)
  {
    if(p->get_left() == temp) p->set_left(l);
    else p->set_right(l);
  }
  else root = l;

  if(l->get_bf() == 1)
  {
      temp->set_bf(0);
      l->set_bf(0);
  }
  else
  {
      temp->set_bf(1);
      l->set_bf(-1);
  }
}

template <typename E>
void AVLTree<E>::RL(AVLNode<E>* &root, AVLNode<E>* temp)
{
  cout << "ROTATION RL" << endl;
  AVLNode<E>* r = temp->get_right();
  AVLNode<E>* rl = r->get_left();
  AVLNode<E>* p = temp->get_up();
  r->set_left(rl->get_right());

  if(r->get_left()) r->get_left()->set_up(r);

  temp->set_right(rl->get_left());

  if (temp->get_right()) temp->get_right()->set_up(temp);

  rl->set_left(temp);
  rl->set_right(r);
  temp->set_up(rl);
  r->set_up(rl);
  rl->set_up(p);

  if(p)
  {
    if(p->get_left() == temp) p->set_left(rl);
    else p->set_right(rl);
  }
  else
    root = rl;

  if (rl->get_bf() == -1) temp->set_bf(1);
  else temp->set_bf(0);

  if(rl->get_bf() == 1) r->set_bf(-1);
  else r->set_bf(0);

  rl->set_bf(0);
}

template <typename E>
void AVLTree<E>::LR(AVLNode<E>* &root, AVLNode<E>* temp)
{
  cout << "ROTATION LR" << endl;
  AVLNode<E>* l = temp->get_left();
  AVLNode<E>* lr = l->get_right();
  AVLNode<E>* p = temp->get_up();
  l->set_right(lr->get_left());

  if(l->get_right()) l->get_right()->set_up(l);

  temp->set_left(lr->get_right());

  if (temp->get_left()) temp->get_left()->set_up(temp);

  lr->set_right(temp);
  lr->set_left(l);
  temp->set_up(lr);
  l->set_up(lr);
  lr->set_up(p);

  if(p)
  {
    if(p->get_left() == temp) p->set_left(lr);
    else p->set_right(lr);
  }
  else
    root = lr;

  if (lr->get_bf() == 1) temp->set_bf(-1);
  else temp->set_bf(0);

  if(lr->get_bf() == -1) l->set_bf(1);
  else l->set_bf(0);

  lr->set_bf(0);
}

template <typename E>
void AVLTree<E>::rebalance(AVLNode<E>* temp)
{
  if(temp->get_bf() == -2)
  {
    if(temp->get_right()->get_bf() == -1) RR(root, temp);
    else RL(root, temp);
  }
  else if(temp->get_bf() == 2)
  {
    if(temp->get_left()->get_bf() == 1) LL(root, temp);
    else LR(root, temp);
  }
}

template <typename E>
void AVLTree<E>::add(E elem, AVLNode<E>* temp)
{
AVLNode<E>* ptr = temp;

  if (empty())
  {
    root = new AVLNode<E>;
    temp = root;
    root->set_up(NULL);
    root->set_key(elem);
  }
  else
  {
    if (elem > temp->get_key())
    {
      if (temp->get_right())
      {
        add(elem, temp->get_right());
      }
      else
      {
        temp->set_right(new AVLNode<E>);
        temp->get_right()->set_key(elem);
        temp->get_right()->set_up(ptr);
      }
    }
    else if(elem < temp->get_key())
    {
      if(temp->get_left())
      {
        add(elem, temp->get_left());
      }
      else
      {
        temp->set_left(new AVLNode<E>);
        temp->get_left()->set_key(elem);
        temp->get_left()->set_up(ptr);
      }
    }
  }
  check_bf(temp);
  rebalance(temp);
}

template <typename E>
void AVLTree<E>::remove(AVLNode<E>* temp)
{
  AVLNode<E> *p, *r, *l, *pr;
  p = temp->get_up(); r = temp->get_right(); l = temp->get_left();

  if((!r) && (!l))
  {
    if(temp == root)
    {
      root =  NULL;
    }
    else
    {
      if(p->get_right() == temp) p->set_right(NULL);
      else p->set_left(NULL);
    }
  }
  else if((l) && (!r))
  {
    if(temp == root)
    {
      root = l;
      l->set_up(NULL);
    }
    else
    {
      if(p->get_right() == temp) p->set_right(l);
      else p->set_left(l);
      l->set_up(p);
    }
  }
  else if((r) && (!l))
  {
    if(temp == root)
    {
      root = r;
      r->set_up(NULL);
    }
    else
    {
      if(p->get_right() == temp) p->set_right(r);
      else p->set_left(r);
      r->set_up(p);
    }
  }
  else
  {
    pr = pred(temp);
    pr->set_right(r);
    r->set_up(pr);

    if(temp == root)
    {
      root = l;
      l->set_up(NULL);
    }
    else
    {
      if(p->get_right() == temp) p->set_right(l);
      else p->set_left(l);
      l->set_up(p);
    }
    while(r)
    {
      check_bf(r);
      rebalance(r);
      r = r->get_up();
    }

  }

  while(p)
  {
    check_bf(p);
    rebalance(p);
    p = p->get_up();
  }

}

template <typename E>
int AVLTree<E>::height(AVLNode<E>* temp)
{
  int ht;
  if(temp)
  {
    int left = height(temp->get_left());
    int right = height(temp->get_right());
    if (left > right) ht = left + 1;
    else ht = right + 1;
    return ht;
  }
  else
  {
    return ht = 0;
  }
}

template <typename E>
void AVLTree<E>::check_bf(AVLNode<E>* temp)
{
  temp->set_bf(height(temp->get_left()) - height(temp->get_right()));
}

template <typename E>
void AVLTree<E>::pre_order(AVLNode<E>* temp)
{
  if(temp)
  {
    cout << "KEY: " << temp->get_key() << " & BF:  " <<
    temp->get_bf() << endl;
    pre_order(temp->get_left());
    pre_order(temp->get_right());
  }
}

template <typename E>
void AVLTree<E>::in_order(AVLNode<E>* temp)
{
  if(temp)
  {
    in_order(temp->get_left());
    cout << "KEY: " << temp->get_key() << " & BF:  " <<
    temp->get_bf() << endl;
    in_order(temp->get_right());
  }
}

template <typename E>
void AVLTree<E>::post_order(AVLNode<E>* temp)
{
  if(temp)
  {
    post_order(temp->get_left());
    post_order(temp->get_right());
    cout << "KEY: " << temp->get_key() << " & BF:  " <<
    temp->get_bf() << endl;
  }

}

template <typename E>
AVLNode<E>* AVLTree<E>::maxNode(AVLNode<E>* temp)
{
  while(temp->get_right() != NULL) temp = temp->get_right();
  return temp;
}

template <typename E>
AVLNode<E>* AVLTree<E>::pred(AVLNode<E>* temp)
{
  return maxNode(temp->get_left());
}

template <typename E>
AVLNode<E>* AVLTree<E>::minNode(AVLNode<E>* temp)
{
  while(temp->get_left()) temp = temp->get_left();
  return temp;
}

template <typename E>
int AVLTree<E>::maxKey(AVLNode<E>* temp)
{
  while(temp->get_right()) temp = temp->get_right();
  return temp->get_key();
}
template <typename E>
int AVLTree<E>::minKey(AVLNode<E>* temp)
{
  while(temp->get_left()) temp = temp->get_left();
  return temp->get_key();
}

template <typename E>
AVLNode<E>* AVLTree<E>::search(E elem, AVLNode<E>* temp)
{
  if(temp)
  {
    if(elem == temp->get_key()) return temp;
    else if(elem < temp->get_key()) return search(elem, temp->get_left());
    else return search(elem, temp->get_right());
  }
  return temp;
}

template <typename E>
void AVLTree<E>::preorder()
{
  pre_order(root);
}

template <typename E>
void AVLTree<E>::inorder()
{
  in_order(root);
}

template <typename E>
void AVLTree<E>::postorder()
{
  post_order(root);
}

template <typename E>
void AVLTree<E>::add_elem(E elem)
{
  int volume, minimum, maximum;
  cout << "Enter the number of new nodes: ";
  cin >> volume;
  if(volume != 1)
  {
    cout << "\nEnter the minimum value of new nodes: ";
    cin >> minimum;
    cout << "\nEnter the maximum value of new nodes: ";
    cin >> maximum;
    for(int i=0; i<=volume; i++)
    {
	  elem = rand() % (maximum-minimum) + minimum;  
      add(elem, root);  
    }
  }
  else
  {
    cout << "\nEnter new node: ";
    cin >> elem;
    add(elem, root);
  }
}

template <typename E>
void AVLTree<E>::remove_elem(E elem)
{
  AVLNode<E>* temp;
  temp = search(elem, root);
  if(temp)
  {
    remove(temp);
  }
}

template <typename E>
void AVLTree<E>::show_root()
{
  if(!empty())
  {
    cout << "ROOT KEY = " << root->get_key() <<
    " || ROOT'S BALANCE FACTOR = " << root->get_bf() << endl;
  }
}

template <typename E>
void AVLTree<E>::show_height()
{
  cout << "TREE HEIGHT = " << height(root) <<endl;
}

#endif
