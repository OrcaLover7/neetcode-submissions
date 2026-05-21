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
            while(k > 0 && s2[i] != s2[k]) k = fail[k-1];

            if(s2[i] == s2[k]) k++;
            fail[i] = k;
        }

        for(int i = 0, k = 0; i < n1; i++){
            while(k > 0 && s1[i] != s2[k]) k = fail[k-1];
            
            if(s1[i] == s2[k]) k++;

            if(k == n2) return true;
        }

        return false;
    }

    void serialize(TreeNode* n1, string &ser){
        if(!n1){
            ser += ",#";
            return;
        }

        ser += "," + to_string(n1->val);
        serialize(n1->left, ser);
        serialize(n1->right, ser);
    }
};
