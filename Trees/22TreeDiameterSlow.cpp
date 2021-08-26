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

int height(BinaryTreeNode<int>* root){
    if (root == NULL){
        return 0;
    }

    return (1 + max(height(root -> leftChild), height(root -> rightChild)));
}

int diameter(BinaryTreeNode<int>* root){
    if (root == NULL){
        return 0;
    }

    int option1 = height(root -> leftChild) + height(root -> rightChild);
    int option2 = diameter(root -> leftChild);
    int option3 = diameter(root -> rightChild);

    return max(option1, max(option2, option3));
}

int main(){
    BinaryTreeNode<int>* root = takeInputLevelWise();
    cout << diameter(root) << endl;
    delete root;

    return 0;
}