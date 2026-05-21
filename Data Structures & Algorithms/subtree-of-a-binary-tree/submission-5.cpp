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
        
        string s1 = "";
        string s2 = "";
        serialize(root, s1);
        serialize(subRoot, s2);
        int n1 = s1.size();
        int n2 = s2.size();

        vector<int> fail(n2, 0);

        for(int i = 1, k = 0; i < n2; i++){
            while(k > 0 && s2[k] != s2[i]) k = fail[k-1];

            if(s2[i] == s2[k]) k++;
            fail[i] = k;
        }

        for(int i = 0, k = 0; i < n1; i++){
            while(k > 0 && s2[k] != s1[i]) k = fail[k-1];

            if(s2[k] == s1[i]) k++;

            if(k == n2) return true;
        }
        return false;
    }

    void serialize(TreeNode* root, string &ser){
        if(!root){
            ser += ",#";
            return;
        }
        
        ser += "," + to_string(root->val);
        serialize(root->left, ser);
        serialize(root->right, ser);

    }
};
