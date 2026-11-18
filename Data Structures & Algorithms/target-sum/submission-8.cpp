class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = (int)nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(abs(target) > sum) return 0;

        vector<vector<int>> dp(n, vector<int>(2*sum + 1, -1));
        return bt(0, nums, target, n, dp, sum);
    }

    int bt(int i, vector<int>& nums, int target, int n, vector<vector<int>>& dp, int offset){
        if(abs(target) > offset) return 0;
        if(i == n){
            return target == 0;
        }
        int shifted_target = target + offset;
        if(dp[i][shifted_target] != -1) return dp[i][shifted_target];
        return dp[i][shifted_target] = bt(i+1, nums, target + nums[i], n, dp, offset) + bt(i+1, nums, target - nums[i], n, dp, offset);
    }
};
