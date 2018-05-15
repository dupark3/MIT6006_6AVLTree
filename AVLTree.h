#include <cmath> // abs
#include <iomanip> // setw
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
    void print();

private:
    Node<T>* root;
    void insert(Node<T>*, Node<T>*, T);
    void right_rotate(Node<T>*, Node<T>*, Node<T>*);
    void left_rotate(Node<T>*, Node<T>*, Node<T>*);
    void fix_AVL(Node<T>*, Node<T>*, Node<T>*);
    void rotate(Node<T>*, Node<T>*, Node<T>*);
    void print_sorted(Node<T>*);
    void print_tree(Node<T>* node, int indent = 0);
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
        if (node->parent && node->parent->parent)
            fix_AVL(node, node->parent, node->parent->parent);
    }
}

template <class T>
void AVLTree<T>::fix_AVL(Node<T>* child, Node<T>* parent, Node<T>* grandparent){
    
    // find and store the heights of left and right children of the grandparent node
    int left_height = -1;
    int right_height = -1;
    if(grandparent && grandparent->left)
        left_height = grandparent->left->height;
    if(grandparent && grandparent->right)
        right_height = grandparent->right->height;
    
    // if heights different by more than 1, call rotate() to find what kind of rotation to do 
    if(std::abs(left_height - right_height) > 1)
        rotate(child, parent, grandparent);
    // if heights are fine, recursively check a higher set of 3 generation nodes
    else if (grandparent->parent)
        fix_AVL(parent, grandparent, grandparent->parent);
}

template <class T>
void AVLTree<T>::rotate(Node<T>* child, Node<T>* parent, Node<T>* grandparent){
    // find out if it is L-L, L-R, R-R, or R-L case
    if(parent == grandparent->left){
        // L-L case, call right_rotate
        if (child == parent->left){
            right_rotate(child, parent, grandparent);
        } 

        // L-R case, call left_rotate then right_rotate
        else if (child == parent->right){
            left_rotate(child, parent, grandparent);
            right_rotate(child, parent, grandparent);
        }

    } 

    else if (parent == grandparent->right){
        // R-R case, call left_rotate
        if (child == parent->right){
            left_rotate(child, parent, grandparent);
        } 

        // R-L case, call right_rotate then left_rotate
        else if (child == parent->right){
            right_rotate(child, parent, grandparent);
            left_rotate(child, parent, grandparent);
        }
    }
}

template <class T>
void AVLTree<T>::right_rotate(Node<T>* child, Node<T>* parent, Node<T>* grandparent){

}

template <class T>
void AVLTree<T>::left_rotate(Node<T>* child, Node<T>* parent, Node<T>* grandparent){
    
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

template <class T>
void AVLTree<T>::print(){
    if(root){
        print_tree(root, 0);
    }
}

template <class T>
void AVLTree<T>::print_tree(Node<T>* node, int indent){
    if(node) {
        if(node->left) 
            print_tree(node->left, indent+4);
        if(node->right) 
            print_tree(node->right, indent+4);
        if (indent)
            std::cout << std::setw(indent) << ' ';
        
        std::cout << node->value << "\n ";
    }
}