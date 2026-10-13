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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root) return result;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            vector<int> curr_level(sz);
            for(int i = 0; i < sz; i++){
                TreeNode* currNode = q.front();
                curr_level[i] = currNode->val;
                if(currNode->left) q.push(currNode->left);
                if(currNode->right) q.push(currNode->right);
                q.pop();
            }
            result.push_back(curr_level);
        }
        return result;
    }
};