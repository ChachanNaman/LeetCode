//98. Validate Binary Search Tree
//https://leetcode.com/problems/validate-binary-search-tree/description/?envType=problem-list-v2&envId=binary-search-tree

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
        bool solve(TreeNode* root, long min, long max) {
            if (root == NULL) {
                return true; // base case
            }
            if (root->val >min && root->val < max)
            // firstly checked the current node then will go to its left and right
            {
                bool left = solve(root->left, min, root->val); // left part recurssive
                bool right = solve(root->right, root->val, max); // right part recurssive
                return left && right;                    // return true if both true
            }
    
            else {
                return false;
            }
        }
        bool isValidBST(TreeNode* root) { 
           return solve(root, LONG_MIN, LONG_MAX);
         }
    };