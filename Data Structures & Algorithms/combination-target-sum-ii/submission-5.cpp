class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<int> combo;
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        bt(nums, 0, target, combo, ans);

        return ans;
    }

    void bt(vector<int>& nums, int start, int target, vector<int>& combo, vector<vector<int>>& ans){
        if(!target){
            ans.push_back(combo);
            return;
        }

        for(int i = start; i < (int)nums.size(); i++){
            int new_target = target - nums[i];
            if(new_target < 0) break;
            if(i > start && nums[i] == nums[i-1]) continue;
            combo.push_back(nums[i]);
            bt(nums, i+1, new_target, combo, ans);
            combo.pop_back();
        }
    }
};
