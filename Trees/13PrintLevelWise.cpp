#include <bits/stdc++.h>
#include <queue>
#include "BinaryTreeNode.h"
using namespace std;

void printLevelWise(BinaryTreeNode<int>* root){
    if (root == NULL){
        return;
    }
    
    queue<BinaryTreeNode<int>* > pendingNodes;
    pendingNodes.push(root);
    
    
    while (pendingNodes.size() != 0){
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout << front -> data << ":";
        if (front -> leftChild != NULL){
            cout << "L:" << front -> leftChild -> data << ",";
            pendingNodes.push(front -> leftChild);
        }
        else {
            cout << "L:" << -1 << ",";
        }
    
        if (front -> rightChild != NULL){
            cout << "R:" << front -> rightChild -> data;
            pendingNodes.push(front -> rightChild);
        }
        else {
            cout << "R:" << -1;
        }
        cout << endl;
    }
}

BinaryTreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout << "Enter root data: ";
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

int main(){
    BinaryTreeNode<int>* root = takeInputLevelWise();
    printLevelWise(root);
    delete root;

    return 0;
}