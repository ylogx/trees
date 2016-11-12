#ifndef NODE_HEADER
#define NODE_HEADER
/*
struct node {
    int info;
    struct node *left, *right;
};

typedef struct node *Node;
*/
typedef int datatype;
class Node {
    public:
        datatype info;
        Node *left, *right;
        Node *father;

        void setLeft(Node*);
        void setRight(Node*);
        bool isLeft();
        bool isRight();

        static Node* getNode(datatype info, Node *left, Node *right);
        static Node* getLeaf(datatype);
};

Node* makeTree();
void assertTreeProperlyConstructed(Node*);


#endif
