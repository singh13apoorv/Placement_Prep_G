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

int sumOfNodes(TreeNode<int>* root) {
    // Write your code here
    int sum = root -> data;
    
    for (int i = 0; i < root -> children.size(); i++){
        sum += sumOfNodes(root -> children[i]);
    }
    
    return sum;
}

int main(){
    TreeNode<int>* root = takeInputLevelWise();
    cout << sumOfNodes(root) << endl;

    return 0;
}