//Is Binary Tree Heap
//https://www.geeksforgeeks.org/problems/is-binary-tree-heap/1?page=1&category=Heap&sortBy=submissions

// Structure of node
/*class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
        int count(struct Node* tree){
            if(tree == NULL){
                return 0;
            }
            int ans = 1+count(tree->left)+count(tree->right);
            return ans;
        }
        bool isCBT(struct Node* tree, int index, int cnt){
            if(tree == NULL){
                return true;
            }
            if(index>= cnt){
                return false; //non CBT condition as skipped order
            }
            else{
                bool left = isCBT(tree->left , 2*index+1, cnt);
                bool right = isCBT(tree->right , 2*index+2,cnt);
                return (left&&right);
            }
        }
        bool isHeapOK(struct Node* root){
            //leaf nodes
            if(root->left == NULL && root->right == NULL){
                return true;
            }
            
            //left child only
            if(root->right == NULL){
                return (root->data >= root->left->data);
            }
            
            if(root->data >= root->left->data && root->data >= root->right->data){
            return isHeapOK(root->left) && isHeapOK(root->right);
        } else {
            return false;
        }
        }
    bool isHeap(Node* tree) {
        // code here
        int totalcount = count(tree);
        int index = 0;
        if(isCBT(tree , index, totalcount)&& isHeapOK(tree)){
            return true;
        }
        else{
            return false;
        }
    }
};