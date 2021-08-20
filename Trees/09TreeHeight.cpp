//1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0

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

int getHeight(TreeNode<int>* root) {
    // Write your code here
    int height = 0;
    for (int i = 0; i < root -> children.size(); i++){
        int smallAns = getHeight(root -> children[i]);
        if (smallAns > height){
            height = smallAns;
        }
    }
    
    return (height + 1);
}

int main(){
    TreeNode<int>* root = takeInputLevelWise();
    cout << getHeight(root) << endl;

    return 0;
}