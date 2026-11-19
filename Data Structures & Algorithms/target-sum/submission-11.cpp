class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = (int)nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(abs(target) > sum) return 0;

        vector<vector<int>> dp(n+1, vector<int>(2*sum + 1, false));
        dp[0][sum] = 1;

        for(int i = 1; i <= n; i++){
            for(int j = -sum; j <= sum; j++){
                int idx = j + sum;
                int ways = 0;

                if(idx + nums[i-1] >= 0 and idx + nums[i-1] <= 2*sum) ways += dp[i-1][idx + nums[i-1]];
                if(idx - nums[i-1] >= 0 and idx - nums[i-1] <= 2*sum) ways += dp[i-1][idx - nums[i-1]];
                
                dp[i][idx] = ways;
            }
        }

        return dp[n][target + sum];
    }

};
