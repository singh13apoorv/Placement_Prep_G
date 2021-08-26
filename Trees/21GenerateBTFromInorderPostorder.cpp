#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
    public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;

BinaryTreeNode<int>* helper(int *postorder, int *inorder, int postst, int postend, int inst, int inend){
    if (postst > postend && inst > inend){
        return NULL;
    }
    
    int rootData = postorder[postend];
    int idxr = -1;
    
    for (int i = inst; i <= inend; i++){
        if (inorder[i] == rootData){
            idxr = i;
            break;
        }
    }
    
    int pstl = postst;
    int pendl = postst + idxr - inst - 1;
    int istl = inst;
    int iendl = idxr - 1;
    
    int pstr = postst + idxr - inst;
    int pendr = postend - 1;
    int istr = idxr + 1;
    int iendr = inend;
    
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    
    BinaryTreeNode<int>* leftc = helper(postorder, inorder, pstl, pendl, istl, iendl);
    BinaryTreeNode<int>* rightc = helper(postorder, inorder, pstr, pendr, istr, iendr);
    
    root -> left = leftc;
    root -> right = rightc;
    
    return root;
}

BinaryTreeNode<int>* buildTree(int *postorder, int postLength, int *inorder, int inLength) {
    // Write your code here
    return helper(postorder, inorder, 0, postLength - 1, 0, inLength - 1);
}

BinaryTreeNode<int> *takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
        
        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void printLevelATNewLine(BinaryTreeNode<int> *root) {
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        BinaryTreeNode<int> *first = q.front();
        q.pop();
        if (first == NULL) {
            if (q.empty()) {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << first->data << " ";
        if (first->left != NULL) {
            q.push(first->left);
        }
        if (first->right != NULL) {
            q.push(first->right);
        }
    }
}

int main() {
    int size;
    cin >> size;
    int *post = new int[size];
    int *in = new int[size];
    for (int i = 0; i < size; i++) cin >> post[i];
    for (int i = 0; i < size; i++) cin >> in[i];
    BinaryTreeNode<int> *root = buildTree(post, size, in, size);
    printLevelATNewLine(root);
}