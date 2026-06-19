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
        unordered_map<int, int> idx_map;

        for(int i = 0; i < (int)inorder.size(); i++) idx_map[inorder[i]] = i;

        return build(preorder, 0, inorder, 0, (int)inorder.size()-1, idx_map);
    }

    TreeNode* build(vector<int>& preorder, int p_idx, vector<int>& inorder, int in_l, int in_r, unordered_map<int, int>& idx_map){
        if(in_l > in_r) return nullptr;

        int root_val = preorder[p_idx];
        auto root = new TreeNode(root_val);

        int inorder_idx = idx_map[root_val];

        int k = inorder_idx-in_l;

        root->left = build(preorder, p_idx+1, inorder, in_l, inorder_idx-1, idx_map);
        root->right = build(preorder, p_idx + k + 1, inorder, inorder_idx+1, in_r, idx_map);

        return root;
    }
};
