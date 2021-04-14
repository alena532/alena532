struct Node
{
    Node *left;
    Node *right;
    Node *prev;
    Node *next;
    int data;
    Node(int  data,Node *left,Node *right);
};
class Tree
{
private:
    Node *root;
    int size;
public:
    Tree();
    Tree(Tree &temp);
    ~Tree();
    void add_node(int number);
    void preorder_print();
    void order_print();
    int Size();
    bool empty();
    void clear();
private:
    Node* _add_node(int  number,Node *leaf);
    void _preorder_print(Node *leaf);
    void _order_print(Node *leaf);
    void _clear(Node* leaf);
};