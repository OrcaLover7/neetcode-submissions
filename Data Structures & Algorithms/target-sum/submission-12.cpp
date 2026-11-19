class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = (int)nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(abs(target) > sum) return 0;

        // vector<vector<int>> dp(n+1, vector<int>(2*sum + 1, false));
        // dp[0][sum] = 1;

        vector<int> dp(2*sum + 1, 0);
        dp[sum] = 1;

        for(int num : nums){
            vector<int> dp_next(2*sum + 1, 0);
            for(int idx = 0; idx <= 2*sum; idx++){
                if(dp[idx] == 0) continue;
                if(idx + num <= 2*sum) dp_next[idx + num] += dp[idx];
                if(idx - num >= 0) dp_next[idx - num] += dp[idx];
            }
            dp = dp_next;
        }

        return dp[target + sum];
    }

};
