class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> combo;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        bt(nums, 0, target, combo, ans);
        return ans;
    }

    void bt(vector<int>& nums, int start, int target, vector<int>& combo, vector<vector<int>>& ans){
        if(target == 0){
            ans.push_back(combo);
            return;
        }

        for(int i = start; i < (int)nums.size(); i++){
            if(target - nums[i] < 0) break;

            combo.push_back(nums[i]);
            bt(nums, i, target - nums[i], combo, ans);
            combo.pop_back();
        }
    }
};
