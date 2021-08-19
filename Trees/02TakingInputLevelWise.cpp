#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

TreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout << "Enter the root data: ";
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>* > pendingNodes;
    pendingNodes.push(root);

    while (pendingNodes.size() != 0){
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();

        int numChild;
        cout << "Enter number of children of " << front -> data << ": ";
        cin >> numChild;

        for (int i = 0; i < numChild; i++){
            int childData;
            cout << "Enter the data for " << i << "th child: ";
            cin >> childData;

            TreeNode<int>* child = new TreeNode<int>(childData);
            front -> children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

void printTreeLevelWise(TreeNode<int>* root){
    queue<TreeNode<int>* > pendingNodes;
    pendingNodes.push(root);

    while (pendingNodes.size() != 0){
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();

        cout << front -> data << ": ";

        for (int i = 0; i < front -> children.size(); i++){
            pendingNodes.push(front -> children[i]);
            cout << front -> children[i] -> data << " ";
        }
        cout << endl;
    }
}

int main(){
    TreeNode<int>* root = takeInputLevelWise();
    printTreeLevelWise(root);

    return 0;
}