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
                int shifted_target = j + sum;
                dp[i][shifted_target] = ((shifted_target - nums[i-1] >= 0 and shifted_target - nums[i-1] <= 2*sum) ? dp[i-1][shifted_target - nums[i-1]] : 0) + ((shifted_target + nums[i-1] >= 0 and shifted_target + nums[i-1] <= 2*sum) ? dp[i-1][shifted_target + nums[i-1]] : 0);
            }
        }

        return dp[n][target + sum];
    }

};
