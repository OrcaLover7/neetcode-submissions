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
    vector<int> ino;
    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);

        return ino[k-1];
    }

    void inorder(TreeNode* root, int k){
        if(!root) return;

        if(ino.size() == k) return;

        inorder(root->left, k);
        ino.push_back(root->val);
        if(ino.size() == k) return;
        inorder(root->right,k);
    }
};
