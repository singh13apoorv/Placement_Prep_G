#include <bits/stdc++.h>
#include <queue>
#include <vector>
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

vector<int>* FindPath(BinaryTreeNode<int>* root, int val){
    if (root == NULL){
        return NULL;
    }

    if (root -> data == val){
        vector<int>* output = new vector<int>();
        output -> push_back(root -> data);
        return output;
    }

    vector<int>* leftOutput = FindPath(root -> leftChild, val);
    if (leftOutput != NULL){
        leftOutput -> push_back(root -> data);
        return leftOutput;
    }

    vector<int>* rightOutput = FindPath(root -> rightChild, val);
    if (rightOutput != NULL){
        rightOutput -> push_back(root -> data);
        return rightOutput;
    }
    else {
        return NULL;
    }
}

int main(){
    BinaryTreeNode<int>* root = takeInputLevelWise();
    vector<int>* ans = FindPath(root, 8);

    for (int i = 0; i < ans -> size(); i++){
        cout << ans -> at(i) << " ";
    }
    cout << endl;

    delete ans;
    delete root;

    return 0;
}