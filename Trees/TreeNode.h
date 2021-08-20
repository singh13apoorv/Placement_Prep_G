#include <vector>
using namespace std;

template <typename T>
class TreeNode{
    public:
    T data;
    vector<TreeNode<T>*> children; //if you want you can mention T. If you don't mention T then also it will be fine.

    TreeNode(T data){
        this -> data = data;
    }

    ~TreeNode(){
        for (int i = 0; i < children.size(); i++){
            delete children[i];
        }
    }
};