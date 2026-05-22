class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> csf;
        sort(nums.begin(), nums.end());

        bt(nums, 0, csf, target, ans);

        return ans;
    }

    void bt(vector<int>& nums, int start, vector<int>& csf, int target, vector<vector<int>>& ans){
        if(target == 0){
            ans.push_back(csf);
            return;
        }

        if(target < 0) return;

        for(int i = start; i < (int)nums.size(); i++){
            if(target-nums[i] < 0) break;
            csf.push_back(nums[i]);
            bt(nums, i, csf, target - nums[i], ans);
            csf.pop_back();
        }
    }
};
