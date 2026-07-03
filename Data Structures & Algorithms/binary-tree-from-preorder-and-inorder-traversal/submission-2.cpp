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
        unordered_map<int, int> index_map;

        for(int i = 0; i < (int)inorder.size(); i++) index_map[inorder[i]] = i;

        return build(preorder, 0, inorder, 0, (int)inorder.size() - 1, index_map);
    }

    TreeNode* build(vector<int>& preorder, int p, vector<int>& inorder, int in_left, int in_right, unordered_map<int, int>& index_map){
        if(in_left > in_right) return nullptr;

        int root_val = preorder[p];
        int inorder_index = index_map[root_val];

        TreeNode* root = new TreeNode(root_val);
        root->left = build(preorder, p+1, inorder, in_left, inorder_index-1, index_map);
        root->right = build(preorder, p + 1 + inorder_index-1 - in_left + 1, inorder, inorder_index+1, in_right, index_map);

        return root;
    }
};
