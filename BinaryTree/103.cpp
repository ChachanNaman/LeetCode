// 103. Binary Tree Zigzag Level Order Traversal
// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // initialsing queue 
        queue<TreeNode*> q;
    
        // initialising ans to store final queue
         vector<vector<int>> ans;
         
        if(root == NULL){
            return ans;
        }
        q.push(root);
        // making counter to keep track of reversing 
        int cnt = 1;
        while(!q.empty()){
            // made vector temp for storing temporary ans before reversing
            vector<int> temp;
            int n = q.size();
            for(int i = 0; i<n ; i++){

                TreeNode* node = q.front();
                q.pop();
                // pushing into vector temp 
                temp.push_back(node->val);

                if(node->left != NULL){
                    q.push(node->left);
                }
                if(node->right != NULL){
                    q.push(node->right);
                }
            }
            // if level 1 then cnt%2 not equal to 0 then same order 
            // level 2 == 0 then reverse right to left 
            //level != 0 then same left to right
            //similary zig zag for further
            if(cnt%2 == 0){
                reverse (temp.begin(), temp.end());
            }
            // pushing temp into ans for final print as its reversed or not 
            ans.push_back(temp);
            cnt++;
            // count ++ to depict going to next level
        }
        return ans;
    }
};