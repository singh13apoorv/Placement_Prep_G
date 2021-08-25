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

bool isPresent(BinaryTreeNode<int>* root, int x){
    if (root == NULL){
        return false;
    }

    if (root -> data == x){
        return true;
    }

    return (false || (isPresent(root -> leftChild, x) || isPresent(root -> rightChild, x)));
}

int main(){
    BinaryTreeNode<int>* root = takeInputLevelWise();
    cout << isPresent(root, 3) << endl;
    delete root;

    return 0;
}