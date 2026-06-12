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
        if(!root) return 0; //unnecessary due to constraints but root->val reference is wrong unless root is not null
        return helper(root, root->val);
    }

    int helper(TreeNode* root, int msf){
        if(!root) return 0;

        int curr = root->val >= msf ? 1 : 0;

        int left = helper(root->left, max(msf, root->val));
        int right = helper(root->right, max(msf, root->val));

        return curr + left + right;
    }
};
