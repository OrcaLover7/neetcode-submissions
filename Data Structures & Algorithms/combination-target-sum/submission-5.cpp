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

        if(start >= (int)nums.size() || target < 0) return;

        combo.push_back(nums[start]);
        bt(nums, start, target-nums[start], combo, ans);
        combo.pop_back();

        bt(nums, start+1, target, combo, ans);
    }
};
