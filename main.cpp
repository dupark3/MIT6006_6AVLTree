#include <iostream>
#include "AVLTree.h"

using namespace std;

int main(){
    AVLTree<int> my_AVL_tree(5);
    my_AVL_tree.insert(7);
    my_AVL_tree.insert(3);
    return 0;
}