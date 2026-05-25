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

        if(target < 0 || start >= (int)nums.size()) return;

        combo.push_back(nums[start]);
        bt(nums, start+1, combo, target-nums[start], ans);
        combo.pop_back();

        while(start+1 < (int)nums.size() && nums[start] == nums[start+1]) start++;


        bt(nums, start+1, combo, target, ans);

    }
};
