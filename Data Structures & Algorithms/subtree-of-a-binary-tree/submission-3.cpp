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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string r = serialize(root);
        string sr = serialize(subRoot);

        int n = r.size();
        int m = sr.size();

        vector<int> fail(m, 0);

        for(int i = 1, k = 0; i < m; i++){
            while(k > 0 && sr[k] != sr[i]) k = fail[k-1];

            if(sr[k] == sr[i]) k++;

            fail[i] = k;
        }

        for(int i = 0, k = 0; i < n; i++){
            while(k > 0 && sr[k] != r[i]) k = fail[k-1];

            if(sr[k] == r[i]) k++;

            if(k == m) return true;
        }

        return false;
    }

    string serialize(TreeNode* root){
        if(!root){
            return ",#";
        }

        return "," + to_string(root->val) + serialize(root->left) + serialize(root->right);
    }
};
