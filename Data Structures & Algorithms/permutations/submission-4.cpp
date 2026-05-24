class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> perm;
        vector<vector<int>> ans;

        bt(nums, 0, perm, ans);
        return ans;
    }

    void bt(vector<int>& nums, int mask, vector<int>& perm, vector<vector<int>>& ans){
        if(perm.size() == nums.size()){
            ans.push_back(perm);
            return;
        }

        for(int i = 0; i < (int)nums.size(); i++){
            if(!(mask & (1 << i))){
                perm.push_back(nums[i]);
                bt(nums, mask | (1 << i), perm, ans);
                perm.pop_back();
            }
        }

    }
};
