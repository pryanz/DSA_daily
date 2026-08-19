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
    int kInorder(TreeNode* node , int k , int & idx){
        if(!node) return -1;
        int val_l = kInorder(node->left, k , idx);
        if(val_l != -1) return val_l;
        idx++;
        if(idx == k) return node->val;
        val_l = kInorder(node->right, k , idx);
        return val_l;
    }
    int kthSmallest(TreeNode* root, int k) {
        int idx = 0;
        return kInorder(root, k , idx);
    }
};