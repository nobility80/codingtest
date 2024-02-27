struct Node {
    int data;
    Node* left;
    Node* right;
};

class BinaryTreeLinkedList {
    public:
    BinaryTreeLinkedList();
    ~BinaryTreeLinkedList();

    Node* CreateNode();
    bool GetData(Node* node, int& data);
    bool SetData(Node* node, int data);

    bool GetLeftNode(Node* parent, Node** node);
    bool GetRightNode(Node* parent, Node** node);

    bool SetLeftNode(Node* parent, Node** child);
    bool SetRightNode(Node* parent, Node** child);

    void RemoveNode(Node* node);
    
    void PreorderPrint(Node* node);
    void InorderPrint(Node* node);
    void PostorderPrint(Node* node);
};