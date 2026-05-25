class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        
        vector<int> combo;
        vector<vector<int>> ans;

        bt(candidates, 0, combo, target, ans);

        return ans;
    }

    void bt(vector<int>& nums, int start, vector<int>& combo, int target, vector<vector<int>>& ans){
        if(target == 0){
            ans.push_back(combo);
            return;
        }

        for(int i = start; i < (int)nums.size(); i++){
            if(i > start && nums[i] == nums[i-1]) continue;
            int new_target = target - nums[i];
            if(new_target < 0) break;
            combo.push_back(nums[i]);
            bt(nums, i+1, combo, new_target, ans);
            combo.pop_back();
        }
    }
};
