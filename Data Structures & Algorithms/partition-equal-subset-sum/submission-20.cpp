class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = (int)nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if(sum % 2) return false;
        int target = sum/2;
        // can we make target from index till i

        vector<vector<bool>> dp(n+1, vector<bool>(target + 1, false));

        for(int i = 0; i <= n; i++) dp[i][0] = true;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= target; j++){
                dp[i][j] = dp[i-1][j];
                if(j >= nums[i-1]) dp[i][j] = dp[i][j] or dp[i-1][j-nums[i-1]];
            }

            if(dp[i][target]) return true;
        }

        return dp[n][target];
     
    }
};
