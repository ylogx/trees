#include "../include/node.h"
#include "../include/traversal.h"
#include <gtest/gtest.h>

/// NodeGetNode
TEST(NodeGetNode, MustReturnNonNullNode) {
    Node *node = Node::getNode(10, NULL, NULL);
    ASSERT_TRUE(node != NULL);
}

TEST(NodeGetNode, MustHaveCorrectInfo) {
    Node *node = Node::getNode(10, NULL, NULL);
    ASSERT_EQ(node->info, 10);
}

TEST(NodeGetNode, MustHaveNoFather) {
    Node *node = Node::getNode(10, NULL, NULL);
    ASSERT_TRUE(node->father == NULL);
}

TEST(NodeGetNode, MustHaveNoSons) {
    Node *node = Node::getNode(10, NULL, NULL);
    /*ASSERT_EQ(node->left, NULL);*/
    ASSERT_TRUE(node->left == NULL);
    ASSERT_TRUE(node->right == NULL);
}

/// NodeGetLeaf
TEST(NodeGetLeaf, MustHaveNoSons) {
    Node *node = Node::getLeaf(10);
    ASSERT_EQ(node->info, 10);
    ASSERT_TRUE(node->left == NULL);
    ASSERT_TRUE(node->right == NULL);
    ASSERT_TRUE(node->father == NULL);
}


/// Node SonsMethods
Node * getDummyTree() {
    return makeTree();
}

TEST(NodeSonsMethods, MustHaveCorrectInfoInSons) {
    Node *tree = getDummyTree();
    ASSERT_TRUE(tree->right != NULL);
    ASSERT_EQ(tree->left->info, 50);
    ASSERT_TRUE(tree->left != NULL);
    ASSERT_EQ(tree->right->info, 150);
}

TEST(NodeSonsMethods, MustHaveCorrectInfoInGrandSons) {
    Node *tree = getDummyTree();
    ASSERT_TRUE(tree->right->left != NULL);
    ASSERT_EQ(tree->right->left->info, 120);
    ASSERT_TRUE(tree->left->right != NULL);
    ASSERT_EQ(tree->left->right->info, 75);
}

TEST(NodeSonsMethods, MustSayLeftWhenLeft) {
    Node *tree = getDummyTree();
    ASSERT_TRUE(tree->left->isLeft());
    ASSERT_FALSE(tree->left->isRight());
}

TEST(NodeSonsMethods, MustSayRightWhenRight) {
    Node *tree = getDummyTree();
    ASSERT_TRUE(tree->right->isRight());
    ASSERT_FALSE(tree->right->isLeft());
}
