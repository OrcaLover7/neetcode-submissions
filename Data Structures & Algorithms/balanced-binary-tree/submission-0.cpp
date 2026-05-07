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
    bool balanced = true;

    bool isBalanced(TreeNode* root) {
        height(root);

        return balanced;
    }

    int height(TreeNode* root){
        if(!root)  return 0;

        int leftH = height(root->left);
        int rightH = height(root->right);

        if(abs(leftH-rightH) > 1){
            balanced = false;
            return -1;
        }

        return 1 + max(leftH, rightH);
    }
};
