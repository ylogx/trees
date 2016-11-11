#ifndef NODE_HEADER
#define NODE_HEADER
/*
struct node {
    int info;
    struct node *left, *right;
};

typedef struct node *Node;
*/
class Node {
    public:
        int info;
        Node *left, *right;
};

#endif
