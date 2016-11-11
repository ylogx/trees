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
};

#endif
