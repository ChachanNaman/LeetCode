/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int findans(vector<int> &ans, TreeNode* root , int B){
    if(root == NULL){
        return 0;
    }
    if(root->val == B){
        ans.push_back(root->val);
        return 1;   //when it returned 1 after founding value then it will go back to parent node or prev node
        //and will give value 1 to right or left then my root node is not prev node 
    }
    int left = findans(ans, root->left , B);
    int right = findans(ans, root->right, B);
    
    if(left==1 || right==1){
        ans.push_back(root->val); //after founding node = val in child node means 1 is there in left or right means have to push parent node too in ans vector
    }
    
    return (left||right);//after pushing parent node to vector , i have to look for parent of that parent node soo returning 1 if found in left or right
}

vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> ans;
    findans(ans , A , B);
    reverse(ans.begin() , ans.end());
    return ans;
}

        5
       / \
      3   8
     / \   \
    2   4   9

/*
findans on node 5
root->val = 5 → not equal to 4
Search left: findans(ans, 3, 4)
Search right will happen if left fails

findans on node 3
root->val = 3 → not equal to 4
Search left: findans(ans, 2, 4)

findans on node 2
root->val = 2 → not equal to 4
Search left: NULL → returns 0
Search right: NULL → returns 0
Neither side found 4 → returns 0 to caller (node 3)

Back at node 3
Left returned 0
Search right: findans(ans, 4, 4)

findans on node 4
Found it!
Push 4 into ans: ans = [4]
Return 1 (true)

Back at node 3
Right returned 1 → means 4 is found in right subtree
Push current node (3) into ans: ans = [4, 3]
Return 1

Back at node 5
Left returned 1 → means 4 is found in left subtree
Push current node (5) into ans: ans = [4, 3, 5]
Return 1

At this point:

ans contains [4, 3, 5] (from target to root).
solve then does:

reverse(ans.begin(), ans.end());

So ans = [5, 3, 4] → path from root to target.
*/