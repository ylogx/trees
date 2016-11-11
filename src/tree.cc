#include "../include/node.h"
#include "../include/traversal.h"

int main(int argc, char *argv[]) {
    Node *ptree = generateTree();
    preorder(ptree);
    return 0;
}
