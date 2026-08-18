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
    int postIdx;
    unordered_map<int,int> hash;
    TreeNode* build(vector<int> &postorder, int start, int end){
        if(start > end) return nullptr;
        TreeNode * node = new TreeNode(postorder[postIdx]);
        postIdx--;
        int mid = hash[node->val];
        node->right = build(postorder, mid + 1, end);
        node->left = build(postorder, start, mid - 1);
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        hash.clear();
        int n = postorder.size();
        for(int i = 0; i < n; i++) hash[inorder[i]] = i;
        postIdx = n - 1;
        return build(postorder, 0, n-1);
    }
};