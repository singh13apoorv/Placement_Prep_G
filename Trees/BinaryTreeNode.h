template <typename T>

class BinaryTreeNode{
    public:
    T data;
    BinaryTreeNode* leftChild;
    BinaryTreeNode* rightChild;

    BinaryTreeNode(T data){
        this -> data = data;
        leftChild = NULL;
        rightChild = NULL;
    }

    ~BinaryTreeNode(){
        delete leftChild;
        delete rightChild;
    }
};