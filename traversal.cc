#include "traversal.h"
#include <iostream>

/** DFS */
void preorder(Node *root) {
    if (root == NULL) {
        return;
    }
    std::cout << root->info << std::endl;
    preorder(root->left);
    preorder(root->right);
}
