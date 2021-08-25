#include <bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;

void printBT(BinaryTreeNode<int>* root){
    if (root == NULL){
        return;
    }

    cout << root -> data << ": ";
    if (root -> leftChild != NULL){
        cout << "L" << root -> leftChild -> data << ", ";
    }
    if (root -> rightChild != NULL){
        cout << "R" << root -> rightChild -> data;
    }
    cout << endl;

    printBT(root -> leftChild);
    printBT(root -> rightChild);
}

BinaryTreeNode<int>* takeInput(){
    int rootData;
    cout << "Enter root data: ";
    cin >> rootData;
    
    if (rootData == -1){
        return NULL;
    }

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int>* left = takeInput();
    BinaryTreeNode<int>* right = takeInput();

    root -> leftChild = left;
    root -> rightChild = right;

    return root;
}

int main(){
    /*BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
    BinaryTreeNode<int>* node1 = new BinaryTreeNode<int>(2);
    BinaryTreeNode<int>* node2 = new BinaryTreeNode<int>(3);

    root -> leftChild = node1;
    root -> rightChild = node2;
    */

    BinaryTreeNode<int>* root = takeInput();
    printBT(root);
    delete root;

    return 0;
}