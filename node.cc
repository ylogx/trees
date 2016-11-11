#include "node.h"
#include "traversal.h"

Node * getNode(void) {
    return new Node();
}

int main() {
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
    preorder(ptree);
    return 0;
}
