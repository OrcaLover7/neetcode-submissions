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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorder_map;
        int n = (int)inorder.size();

        for(int i = 0; i < n; i++) inorder_map[inorder[i]] = i;
        return build(preorder, inorder, 0, inorder_map, 0, n-1);
    }

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int pre_idx, unordered_map<int, int>& inorder_map, int l, int r){
        if(l > r) return nullptr;
        
        int root_val = preorder[pre_idx];
        int root_idx = inorder_map[root_val];
        
        TreeNode* root = new TreeNode(root_val);
        root->left = build(preorder, inorder, pre_idx + 1, inorder_map, l, root_idx-1);
        root->right = build(preorder, inorder, pre_idx + (root_idx - l + 1), inorder_map, root_idx+1, r);
        return root;
    }
};
