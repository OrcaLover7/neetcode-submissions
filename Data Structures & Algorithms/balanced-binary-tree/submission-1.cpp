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

    bool isBalanced(TreeNode* root) {
        int balanced = 1;
        height(root, balanced);

        return balanced == 1;
    }

    int height(TreeNode* root, int& balanced){
        if(!root)  return 0;

        int leftH = height(root->left, balanced);
        int rightH = height(root->right, balanced);

        if(abs(leftH-rightH) > 1){
            balanced = 0;
            return -1;
        }

        if(!balanced) return -1;

        return 1 + max(leftH, rightH);
    }
};
