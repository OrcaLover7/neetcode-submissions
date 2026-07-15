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
        unordered_map<int, int> inorder_index_map;
        int n = (int)inorder.size();

        for(int i = 0; i < n; i++) inorder_index_map[inorder[i]] = i;

        return build(preorder, 0, inorder, 0, n-1, inorder_index_map);
    }

    TreeNode* build(vector<int>& preorder, int pre_index, vector<int>& inorder, int in_left, int in_right, unordered_map<int, int>& inorder_index_map){
        if(in_left > in_right) return nullptr;

        int root_val = preorder[pre_index];
        int root_index = inorder_index_map[root_val];
        auto root = new TreeNode(root_val);

        root->left = build(preorder, pre_index+1, inorder, in_left, root_index-1, inorder_index_map);
        root->right = build(preorder, pre_index+1+(root_index - in_left), inorder, root_index+1, in_right, inorder_index_map);

        return root;

    }


};
