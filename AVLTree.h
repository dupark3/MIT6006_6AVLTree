#include <cmath> // abs
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
    void print_sorted();

private:
    Node<T>* root;
    void insert(Node<T>*, Node<T>*, T);
    void right_rotate(Node<T>*);
    void left_rotate(Node<T>*);
    void fix_AVL(Node<T>*);
    void rotate(Node<T>*, Node<T>*, Node<T>*);
    void print_sorted(Node<T>*);
};

template <class T>
class Node{
friend class AVLTree<T>;
public: 
    Node() : left(0), right(0), parent(0), height(-1) { }
    Node(T val) : value(val), left(0), right(0), parent(0), height(0) { }

private:
    T value;
    Node<T>* left;
    Node<T>* right;
    Node<T>* parent;
    int height;
};



/******************* Member and Nonmember Function Definitions ***************/


template <class T>
void AVLTree<T>::insert(T val){
    if (root){
        if (val < root->value){
            ++root->height;
            insert(root->left, root, val);
        } else if (val > root->value){
            ++root->height;
            insert(root->right, root, val);
        }
    } else {
        root = new Node<T>(val);
    }
}

template <class T>
void AVLTree<T>::insert(Node<T>* node, Node<T>* parent, T val){
    if (node){
        if (val < node->value){
            ++node->height;
            insert(node->left, node, val);
        } else if (val > node->value){
            ++node->height;
            insert(node->right, node, val);
        }
    } else {
        node = new Node<T>(val);
        node->parent = parent;
        if(val < parent->value)
            parent->left = node;
        else if (val > parent->value)
            parent->right = node;
        fix_AVL(node);
    }
}

template <class T>
void AVLTree<T>::fix_AVL(Node<T>* node){
    int left_height = -1;
    int right_height = -1;
    Node<T>* grandparent = node->parent->parent;
    Node<T>* parent = node->parent;
    if(parent && grandparent && grandparent->left)
        left_height = grandparent->left->height;
    if(parent && grandparent && grandparent->right)
        right_height = grandparent->right->height;
    if(std::abs(left_height - right_height) > 1)
        rotate(grandparent, parent, node);
}

template <class T>
void AVLTree<T>::rotate(Node<T>* grandparent, Node<T>* parent, Node<T>* child){

}

template <class T>
void AVLTree<T>::right_rotate(Node<T>* node){

}

template <class T>
void AVLTree<T>::left_rotate(Node<T>* node){
    
}

template <class T>
void AVLTree<T>::print_sorted(){
    if(root){
        print_sorted(root->left);
        std::cout << root->value << ' ';
        print_sorted(root->right);
        std::cout << std::endl;
    }
}

template <class T>
void AVLTree<T>::print_sorted(Node<T>* node){
    if (node){
        print_sorted(node->left);
        std::cout << node->value << ' ';
        print_sorted(node->right);
    }
}