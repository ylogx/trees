#include "../include/traversal.h"
#include <iostream>
#include <cassert>

Node * makeTree() {
    Node *ptree;
    Node *p, *q;
    p = Node::getNode(50, Node::getLeaf(25), Node::getLeaf(75));
    q = Node::getNode(150, Node::getLeaf(120), Node::getLeaf(170));
    ptree = Node::getNode(100, p, q);
    assertTreeProperlyConstructed(ptree);
    return ptree;
}

void assertTreeProperlyConstructed(Node *ptree) {
    assert(ptree != NULL);
    assert(ptree->info == 100);
    assert(ptree->right->info == 150);
    assert(ptree->left->info == 50);
    assert(ptree->right->isRight());
    assert(!ptree->left->isRight());
    assert(ptree->left->isLeft());
    assert(!ptree->right->isLeft());
}

/** DFS */
void preorder(Node *root) {
    if (root == NULL) {
        return;
    }
    std::cout << root->info << std::endl;
    preorder(root->left);
    preorder(root->right);
}
