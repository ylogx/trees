#include "../include/node.h"
#include "../include/traversal.h"

Node * getNode(void) {
    return new Node();
}

Node * generateTree() {
    Node *ptree;
    Node *p, *q;
    ptree = getNode();
    p = getNode();
    q = getNode();
    ptree->info = 10;
    ptree->left = p;
    ptree->right = q;
    p->info = 9;
    q->info = 11;
    return ptree;
}


int main() {
    Node *ptree = generateTree();
    preorder(ptree);
    return 0;
}
