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
    // one idea is to do bfs or dfs and save the paretns which would allow us to connect the root to node paths for p and q
    // we could find the first common node on the path back from node to root
    // but I wanna know how I can make use of the BST property
    // if root->val lies between p and q, then root is teh answer
    // else we check in one the subtrees
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val < p->val && root->val < q->val) return lowestCommonAncestor(root->right, p, q);

        if(root->val > p->val && root->val > q->val) return lowestCommonAncestor(root->left, p, q);

        return root;
    }
};
