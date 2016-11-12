#ifndef TRAVERSAL_HEADER
#define TRAVERSAL_HEADER

#include "node.h"

Node* makeTree();
void assertTreeProperlyConstructed(Node*);

void preorder(Node *root);

#endif  //TRAVERSAL_HEADER
