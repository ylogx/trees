#include "../include/node.h"
#include "../include/traversal.h"

int main(int argc, char *argv[]) {
    Node *ptree = makeTree();
    preorder(ptree);
    return 0;
}
