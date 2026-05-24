class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> perm;
        vector<vector<int>> ans;
        vector<bool> visited((int)nums.size(), false);

        bt(nums, perm, visited, ans);
        return ans;
    }

    void bt(vector<int>& nums, vector<int>& perm, vector<bool>& v, vector<vector<int>>& ans){
        if((int)perm.size() == (int)nums.size()){
            ans.push_back(perm);
            return;
        }

        for(int i = 0; i < (int)nums.size(); i++){
            if(!v[i]){
                perm.push_back(nums[i]);
                v[i] = true;
                bt(nums, perm, v, ans);
                v[i] = false;
                perm.pop_back();
            }
        }
    }
};
