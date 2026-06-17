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
        unordered_map<int, int> indexes;
        int n = (int)inorder.size();

        for(int i = 0; i < n; i++) indexes[inorder[i]] = i;

        return build(preorder, 0, inorder, 0, n-1, indexes);
    }

    TreeNode* build(vector<int>& preorder, int p_idx, vector<int>& inorder, int in_l, int in_r, unordered_map<int, int>& idxs){
        if(in_l > in_r) return nullptr;

        int root_elem = preorder[p_idx];
        auto root = new TreeNode(root_elem);

        int in_idx = idxs[root_elem];

        int k = in_idx - in_l;

        root->left = build(preorder, p_idx+1, inorder, in_l, in_idx-1, idxs);
        root->right = build(preorder, p_idx+k+1, inorder, in_idx+1, in_r, idxs);

        return root;
    }
};
