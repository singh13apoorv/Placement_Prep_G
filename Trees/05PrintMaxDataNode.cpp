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

TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    // Write your code here
    TreeNode<int>* maxNode = root;
    
    for (int i = 0; i < root -> children.size(); i++){
        if (maxNode -> data < root -> children[i] -> data){
            maxNode = root -> children[i];
        }
        
        TreeNode<int>* smallAns = maxDataNode(root -> children[i]);
        if (maxNode -> data < smallAns -> data){
            maxNode = smallAns;
        }
    }
    
    return maxNode;
}

int main(){
    TreeNode<int>* root = takeInputLevelWise();
    TreeNode<int>* maxNodeData = maxDataNode(root);
    cout << maxNodeData -> data << endl;

    return 0;
}