/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void solve(TreeNode* &root,  queue<TreeNode*> &q,vector<vector<int>> &ans){
    q.push(root);
    q.push(NULL);
    bool leftToRight = true;  //initially making it true coz root value after insetion changes to false 
    //reverse the value in queue at before and after null to make it zigzag
    vector<int> level;
    
    while(!q.empty()){

        TreeNode* temp = q.front();
        q.pop();
        if(temp == NULL){
            //firstly 
            if (!leftToRight){//if marked false then reverse
                reverse(level.begin(), level.end());
            }//completed one level , now next level normal insert
            ans.push_back(level);
            level.clear();
            
            if(!q.empty()) q.push(NULL);
            leftToRight = !leftToRight;
        }
        else{
            level.push_back(temp->val); //firstly push element in levels normally
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
}
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    queue<TreeNode*> q;
    vector<vector<int>> ans;
    solve(A, q , ans);
    return ans;
}
