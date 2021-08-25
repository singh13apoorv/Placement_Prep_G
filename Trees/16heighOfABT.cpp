#include <bits/stdc++.h>
#include <queue>
#include "BinaryTreeNode.h"
using namespace std;

BinaryTreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout << "Enter root data:";
    cin >> rootData;

    if (rootData == -1){
        return NULL;
    }

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>* > pendingNodes;

    pendingNodes.push(root);

    while (pendingNodes.size() != 0){
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();

        int lc;
        cout << "Enter left child for " << front -> data << " :";
        cin >> lc;
        if (lc != -1){
            BinaryTreeNode<int>* lchild = new BinaryTreeNode<int>(lc);
            front -> leftChild = lchild;
            pendingNodes.push(lchild);
        }

        int rc;
        cout << "Enter right child for " << front -> data << " :";
        cin >> rc;
        if (rc != -1){
            BinaryTreeNode<int>* rchild = new BinaryTreeNode<int>(rc);
            front -> rightChild = rchild;
            pendingNodes.push(rchild);
        }
    }

    return root;
}

int height(BinaryTreeNode<int>* root) {
    // Write our code here
    if (root == NULL){
        return 0;
    }
    
    int smallAnsl = height(root -> leftChild);
    int smallAnsR = height(root -> rightChild);
    
    if (smallAnsl >= smallAnsR){
        return 1 + smallAnsl;
    }
    
    return 1 + smallAnsR;
}

int main(){
    BinaryTreeNode<int>* root = takeInputLevelWise();
    cout << height(root) << endl;
    delete root;

    return 0;
}