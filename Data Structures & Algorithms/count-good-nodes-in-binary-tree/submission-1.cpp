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
    int goodNodes(TreeNode* root) {
        int msf = -101;

        return good(root, msf);
    }

    int good(TreeNode* root, int msf){
        if(!root) return 0;

        return good(root->left, max(root->val, msf)) + good(root->right, max(root->val, msf)) + (root->val < msf ? 0 : 1);
    }
};
