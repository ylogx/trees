#include "../include/node.h"
#include "../include/traversal.h"
#include <gtest/gtest.h>

TEST(getNode, MustReturnNonNullNode) {
    Node *node = Node::getNode(10, NULL, NULL);
    ASSERT_TRUE(node != NULL);
}

TEST(getNode, MustHaveCorrectInfo) {
    Node *node = Node::getNode(10, NULL, NULL);
    ASSERT_EQ(node->info, 10);
}

TEST(getNode, MustHaveNoFather) {
    Node *node = Node::getNode(10, NULL, NULL);
    ASSERT_TRUE(node->father == NULL);
}

TEST(getNode, MustHaveNoSons) {
    Node *node = Node::getNode(10, NULL, NULL);
    /*ASSERT_EQ(node->left, NULL);*/
    ASSERT_TRUE(node->left == NULL);
    ASSERT_TRUE(node->right == NULL);
}

TEST(getLeaf, MustHaveNoSons) {
    Node *node = Node::getLeaf(10);
    ASSERT_EQ(node->info, 10);
    ASSERT_TRUE(node->left == NULL);
    ASSERT_TRUE(node->right == NULL);
    ASSERT_TRUE(node->father == NULL);
}



Node * getDummyTree() {
    return makeTree();
}

TEST(sonsMethods, MustSayLeftWhenLeft) {
    Node *tree = getDummyTree();
    ASSERT_TRUE(tree->left->isLeft());
    ASSERT_FALSE(tree->left->isRight());
}

TEST(sonsMethods, MustSayRightWhenRight) {
    Node *tree = getDummyTree();
    ASSERT_TRUE(tree->right->isRight());
    ASSERT_FALSE(tree->right->isLeft());
}
