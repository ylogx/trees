#include <cassert>
#include <cstdlib>

#include "../include/node.h"


Node * Node::getNode(datatype info, Node *left, Node *right) {
    Node * node = new Node();
    node->info = info;
    node->setLeft(left);
    node->setRight(right);
    return node;
}

Node * Node::getLeaf(datatype info) {
    return Node::getNode(info, NULL, NULL);
    //Node *leftLeaf = Node::getNode(-1, NULL, NULL);
    //Node *rightLeaf = Node::getNode(-1, NULL, NULL);
    //return Node::getNode(info, leftLeaf, rightLeaf);
}

void Node::setLeft(Node *left) {
    this->left = left;
    if (this->left != NULL) {
        this->left->father = this;
    }
}

void Node::setRight(Node *right) {
    this->right = right;
    if (this->right != NULL) {
        this->right->father = this;
    }
}

bool Node::isLeft() {
    return this->father->left == this;
}

bool Node::isRight() {
    return this->father->right == this;
}

