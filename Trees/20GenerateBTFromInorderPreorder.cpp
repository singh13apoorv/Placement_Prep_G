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

BinaryTreeNode<int>* helper(int *preorder, int *inorder, int stpre, int edpre, int stinod, int edin){
    if (stpre > edpre && stinod > edin){
        return NULL;
    }
    int rootData = preorder[stpre];
    int idxr = -1;
    
    for (int i = stinod; i <= edin; i++){
        if (inorder[i] == rootData){
            idxr = i;
            break;
        }
    }
    
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    int lenOleft = idxr - 1 - stinod;
    
    BinaryTreeNode<int>* leftc = helper(preorder, inorder, stpre + 1, stpre + 1 + lenOleft, stinod, idxr - 1);
    BinaryTreeNode<int>* rightc = helper(preorder, inorder, stpre + 1 + lenOleft + 1, edpre, idxr + 1, edin);
    
    root -> left = leftc;
    root -> right = rightc;
    
    return root;
}

BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) {
    // Write your code here
    BinaryTreeNode<int>* root = helper(preorder, inorder, 0, preLength - 1, 0, inLength - 1);
    return root;
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
    int *pre = new int[size];
    int *in = new int[size];
    for (int i = 0; i < size; i++) cin >> pre[i];
    for (int i = 0; i < size; i++) cin >> in[i];
    BinaryTreeNode<int> *root = buildTree(pre, size, in, size);
    printLevelATNewLine(root);
}