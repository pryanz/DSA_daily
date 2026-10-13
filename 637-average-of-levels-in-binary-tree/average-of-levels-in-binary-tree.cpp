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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        if(!root) return result;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            double curr_level = 0;
            for(int i = 0; i < sz; i++){
                TreeNode* currNode = q.front();
                curr_level += currNode->val;
                if(currNode->left) q.push(currNode->left);
                if(currNode->right) q.push(currNode->right);
                q.pop();
            }
            result.push_back(curr_level/(double)sz);
        }
        return result;
    }
};