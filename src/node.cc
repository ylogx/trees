#include <cassert>
#include <cstdlib>

#include "../include/node.h"
#include "../include/traversal.h"

Node * getNode(datatype info, Node *left, Node *right) {
    Node * node = new Node();
    node->info = info;
    node->left = left;
    node->right = right;
    return node;
}

Node * getLeaf(datatype info) {
    Node *node = new Node();
    node->info = info;
    return node;
}

Node * generateTree() {
    Node *ptree;
    Node *p, *q;
    p = getNode(8, getLeaf(7), getLeaf(9));
    q = getLeaf(11);
    ptree = getNode(10, p, q);
    assert(ptree != NULL);
    assert(ptree->info == 10);
    assert(ptree->right->info == 11);
    assert(ptree->left->info == 8);
    return ptree;
}

#include <gtest/gtest.h>
int main(int argc, char *argv[]) {
   ::testing::InitGoogleTest(&argc, argv);
    Node *ptree = generateTree();
    preorder(ptree);
    return RUN_ALL_TESTS();
}
