#include <iostream>
#include <cstdlib>
using namespace std;

/*
------------------------------ AVL - NODE ------------------------------
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
$                                                                      $
$ class AVLNode represents the node of the AVLTree                     $
$                                                                      $
$ up    - means the parent's address                                   $
$ left  - means the left son's address                                 $
$ right - means the right son's address                                $
$ key   - tree's nodes are ordered according to this value             $                                                                     $
$ bf    - gives the info about balance factor                          $
$                                                                      $
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
*/

template <typename E>
class AVLNode{
public:
  AVLNode() { right = NULL; left = NULL; bf=0; };    // constructor
  ~AVLNode() { delete right; delete left; };         // destructor

  int get_bf() const { return bf; };                 //
  E get_key() const { return key; };                 //
  AVLNode<E>* get_up() const { return up; };         // getters
  AVLNode<E>* get_left() const { return left; };     //
  AVLNode<E>* get_right() const { return right; };   //

  void set_bf(int temp) { bf = temp; };              //
  void set_key(E temp) { key = temp; };              //
  void set_up(AVLNode<E> *temp) { up = temp; };      // setters
  void set_left(AVLNode<E> *temp) { left = temp; };  //
  void set_right(AVLNode<E> *temp) {right = temp; }; //
private:
  AVLNode<E>* up;
  AVLNode<E>* left;
  AVLNode<E>* right;
  int bf;
  E key;
};
