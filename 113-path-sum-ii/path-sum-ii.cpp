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
    void dfs(TreeNode* root, int target, vector<vector<int>> & ans, vector<int>& temp){
        if(!root) return;
        temp.push_back(root->val);
        if(!root->left && !root->right && target == root->val) ans.push_back(temp);
        if(root->left) dfs(root->left, target - root->val, ans, temp);
        if(root->right) dfs(root->right, target - root->val, ans, temp);
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;
        dfs(root, targetSum, ans, temp);
        return ans;
    }
};