class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = (int)nums.size();
        int S = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> dp(n, vector<int> (2*S + 1, INT_MIN));

        return bt(nums, 0, 0, target, n, S, dp);
    }

    int bt(vector<int>& nums, int sum, int i, int target, int n, int S, vector<vector<int>>& dp){
        if(i == n) return target == sum;

        if(dp[i][sum + S] != INT_MIN) return dp[i][sum + S];

        return dp[i][sum + S] = bt(nums, sum + nums[i], i+1, target, n, S, dp) + bt(nums, sum - nums[i], i+1, target, n, S, dp);
    }
};
