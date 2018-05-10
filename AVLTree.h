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
    void insert(T);

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

    void insert(Node<T>*, T);
};

template <class T>
void AVLTree<T>::insert(T val){
    if (root){
        if (val < root->val){
            insert(root->left, val);
        } else if (root->val < val){
            insert(root->right, val);
        }
    } else {
        root->value = val;
    }
}

template <class T>
void AVLTree<T>::insert(Node<T>* node, T val){
    if (node){
        if (val < node->val){
            insert(node->left, val);
        } else if (node->val < val){
            insert(node->right, val);
        }
    } else {
        node->value = val;
    }
}

template <class T>
void AVLTree<T>::right_rotate(Node<T>* node){

}

template <class T>
void AVLTree<T>::left_rotate(Node<T>* node){
    
}