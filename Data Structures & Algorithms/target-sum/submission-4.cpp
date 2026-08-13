class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = (int)nums.size();
        int S = accumulate(nums.begin(), nums.end(), 0);
        if(target > S or target < -S) return 0;
        vector<vector<int>> dp(n, vector<int> (2*S + 1, INT_MIN));
        return bt(nums, 0, 0, S, target, n, dp);
    }

    int bt(vector<int>& nums, int index, int sum, int S, int target, int n, vector<vector<int>>& dp){
        if(index == n) return sum == target;

        if(dp[index][sum + S] != INT_MIN) return dp[index][sum + S];

        return dp[index][sum + S] = bt(nums, index+1, sum + nums[index], 
        S, target, n, dp) + bt(nums, index+1, sum - nums[index], S, target, n, dp);
    }
};
