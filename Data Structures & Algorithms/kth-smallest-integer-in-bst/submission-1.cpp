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
    //simplest is to do inorder and give the kth element (k-1)
    int count = 0, result = 0;
    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);

        return result;
    }

   
    void inorder(TreeNode* root, int k) {
        if (!root || count >= k) return;
        inorder(root->left, k);
        if (++count == k) { result = root->val; return; }
        inorder(root->right, k);
    } 
};
