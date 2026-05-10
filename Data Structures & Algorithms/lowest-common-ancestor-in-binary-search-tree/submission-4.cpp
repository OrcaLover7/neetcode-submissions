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
        // while (root) {                                                                                                                       
        //     if (p->val < root->val && q->val < root->val) root = root->left;
        //     else if (p->val > root->val && q->val > root->val) root = root->right;                                                           
        //     else return root;                                                                                                                
        // }                                                                                                                                    
        // return nullptr;
        if(root == p || root == q) return root;

        if(p->val < root->val && q->val < root->val) return lowestCommonAncestor(root->left, p, q);
        else if(p->val > root->val && q->val > root->val)
            return lowestCommonAncestor(root->right, p, q);
        
        return root;
    }
};
