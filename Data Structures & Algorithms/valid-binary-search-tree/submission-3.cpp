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
    //inorder traversla should be sorted is one way
    bool isValidBST(TreeNode* root) {
        return isv(root, -1001, 1001);
    }

    bool isv(TreeNode* root, int mn, int mx){
        if(!root) return true;

        if(root->val <= mn || root->val >= mx) return false;

        return isv(root->left, mn, root->val) && isv(root->right, root->val, mx);
    }
};
