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
    int ans;
    void dfs(TreeNode * node, int maxVal){
        if(!node) return;
        if(node->val >= maxVal) ans++;
        maxVal = max(maxVal,node->val);
        dfs(node->right,maxVal);
        dfs(node->left, maxVal);
    }
    int goodNodes(TreeNode* root) {
        ans = 0;
        dfs(root, INT_MIN);
        return ans;
    }
};