#include <iostream>
#include "AVLTree.h"

using namespace std;

int main(){
    AVLTree<int> my_AVL_tree(5);
    my_AVL_tree.print_sorted(); // 5
    // my_AVL_tree.print();
    my_AVL_tree.insert(7);
    my_AVL_tree.print_sorted(); // 5 7
    // my_AVL_tree.print();
    my_AVL_tree.insert(3);
    my_AVL_tree.print_sorted(); // 3 5 7, AVL-true
    // my_AVL_tree.print();
    my_AVL_tree.insert(9);
    my_AVL_tree.insert(11); // 3 5 7 9 11, AVL-false, R-R
    my_AVL_tree.insert(2);
    my_AVL_tree.insert(-2);
    my_AVL_tree.insert(4);
    my_AVL_tree.insert(6);
    my_AVL_tree.insert(8);
    my_AVL_tree.print_sorted(); 
    my_AVL_tree.print();

    return 0;
}