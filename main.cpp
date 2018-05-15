#include <iostream>
#include "AVLTree.h"

using namespace std;

int main(){
    AVLTree<int> my_AVL_tree(5);
    my_AVL_tree.insert(7);
    my_AVL_tree.insert(3);
    my_AVL_tree.print_sorted(); // 3 5 7, AVL-true
    my_AVL_tree.insert(9);
    my_AVL_tree.insert(11); // 3 5 7 9 11, AVL-false
    my_AVL_tree.print_sorted();

    return 0;
}