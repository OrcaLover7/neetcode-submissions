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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levels;
        if(!root) return levels;
        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()){
            int sz = q.size();

            vector<int> curr_level;

            for(int i = 0; i < sz; i++){
                auto curr_node = q.front();
                q.pop();

                curr_level.push_back(curr_node->val);
                if(curr_node->left) q.push(curr_node->left);
                if(curr_node->right) q.push(curr_node->right);
            }
            levels.push_back(curr_level);
        }

        return levels;
    }
};
