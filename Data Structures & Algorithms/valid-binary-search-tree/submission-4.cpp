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
        return isvalid(root, -1001, 1001);
    }

    bool isvalid(TreeNode* root, int mn, int mx){
        if(!root) return true;

        int rv = root->val;

        if(rv <= mn || rv >= mx) return false;

        return isvalid(root->left, mn, rv) && isvalid(root->right, rv, mx);
    }
};
