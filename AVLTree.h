#include <iostream>

// AVL tree has no greater than a difference of 1 in subtree size to its left and right
//

// forward declation
template <class T> class Node;

template <class T>
class AVLTree{
public:
    AVLTree() : root(0) { }
    AVLTree(T val) : root(new Node<T>(val)) { }

private:
    Node<T>* root;
};

template <class T>
class Node{
friend class AVLTree<T>;
public: 
    Node() : left(0), right(0), parent(0), height(-1) { }
    Node(T val) : element(val), left(0), right(0), parent(0), height(0) { }

private:
    T element;
    Node<T>* left;
    Node<T>* right;
    Node<T>* parent;
    int height;
};