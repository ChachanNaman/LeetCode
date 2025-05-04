//108. Convert Sorted Array to Binary Search Tree
//https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/?envType=problem-list-v2&envId=binary-search-tree


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
        TreeNode* solve(int s, int e, vector<int>& nums) {
            if (s > e) {
                return NULL;
                // base case means if start element >end element means not sorted
                // soo there's nothing i can do
            }
            int mid = s + (e - s) / 2;
            TreeNode* root =
                new TreeNode(nums[mid]); // in sorted array always root node is mid
                                         // element coz its sorted
            root->left = solve(s, mid - 1, nums);
            root->right = solve(mid + 1, e, nums);
            return root;
        }
        TreeNode* sortedArrayToBST(vector<int>& nums) {
            int s = 0;
            int e = nums.size() - 1;
            return solve(s, e, nums);
        }
    };