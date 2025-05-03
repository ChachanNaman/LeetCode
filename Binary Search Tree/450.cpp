//450. Delete Node in a BST
//https://leetcode.com/problems/delete-node-in-a-bst/description/?envType=problem-list-v2&envId=binary-search-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    public:
        TreeNode* minval(TreeNode* root) {
            TreeNode* temp = root;
            while (temp->left != NULL) {
                temp = temp->left;
            }
            return temp;
        }
        TreeNode* deleteNode(TreeNode* root, int key) {
            if (root == NULL) { // BASE CASE
                return root;
            }
            if (root->val == key) {
                // 0 child
                if (root->left == NULL && root->right == NULL) {
                    delete root;
                    return NULL; // returning null to parent as there were no child
                }
                // 1 child : (left child or right child)
    
                // left child
                if (root->left != NULL && root->right == NULL) {
                    TreeNode* temp = root->left;
                    delete root;
                    return temp;
                }
    
                // right child
                if (root->left == NULL && root->right != NULL) {
                    TreeNode* temp = root->right;
                    delete root;
                    return temp;
                }
    
                // 2 childs
                if (root->left != NULL && root->right != NULL) {
                    // we can do by two ways by going to max value in left subtree
                    // of root OR min value in right subtree of root
                    int mini = minval(root->right)->val;
                    root->val = mini;
                    root->right = deleteNode(root->right, mini);
                    return root;
                }
            } else if (key < root->val) {
                root->left = deleteNode(root->left, key);
    
            } else {
                root->right = deleteNode(root->right, key);
            }
            return root;
        }
    };